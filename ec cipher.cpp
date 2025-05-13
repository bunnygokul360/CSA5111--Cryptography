#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
const float english_freq[] = {
    8.2, 1.5, 2.8, 4.3, 12.7, 2.2, 2.0, 6.1, 7.0, 0.15, 0.77, 4.0, 2.4,
    6.7, 7.5, 1.9, 0.095, 6.0, 6.3, 9.1, 2.8, 0.98, 2.4, 0.15, 2.0, 0.074
};

typedef struct {
    int shift;
    char *plaintext;
    float score;
} DecryptionAttempt;

void count_letters(const char *text, int counts[26]) {
    memset(counts, 0, 26 * sizeof(int));
    for (int i = 0; text[i]; i++) {
        if (isalpha(text[i])) {
            counts[tolower(text[i]) - 'a']++;
        }
    }
}

float calculate_score(const int counts[26], int total) {
    if (total == 0) return -1000.0; 
    
    float score = 0;
    for (int i = 0; i < 26; i++) {
        float expected = english_freq[i];
        float observed = (counts[i] * 100.0) / total;
        if (expected > 0) {
            float diff = observed - expected;
            score -= (diff * diff) / expected;
        }
    }
    return score;
}

void frequency_attack(const char *ciphertext, int top_n) {
    int counts[26] = {0};
    int total = 0;
    count_letters(ciphertext, counts);
    
    for (int i = 0; i < 26; i++) {
        total += counts[i];
    }
    
    if (total == 0) {
        printf("No alphabetic characters found in ciphertext.\n");
        return;
    }
    
    int len = strlen(ciphertext);
    DecryptionAttempt attempts[26];
    
    for (int shift = 0; shift < 26; shift++) {
        attempts[shift].shift = shift;
        attempts[shift].plaintext = (char *)malloc(len + 1);
        if (!attempts[shift].plaintext) {
            perror("Memory allocation failed");
            exit(EXIT_FAILURE);
        }
        for (int i = 0; i < len; i++) {
            if (isalpha(ciphertext[i])) {
                char base = islower(ciphertext[i]) ? 'a' : 'A';
                char decrypted = ((ciphertext[i] - base - shift + 26) % 26) + base;
                attempts[shift].plaintext[i] = decrypted;
            } else {
                attempts[shift].plaintext[i] = ciphertext[i];
            }
        }
        attempts[shift].plaintext[len] = '\0';
        
        int decrypted_counts[26] = {0};
        count_letters(attempts[shift].plaintext, decrypted_counts);
        attempts[shift].score = calculate_score(decrypted_counts, total);
    }
    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < 25 - i; j++) {
            if (attempts[j].score < attempts[j+1].score) {
                DecryptionAttempt temp = attempts[j];
                attempts[j] = attempts[j+1];
                attempts[j+1] = temp;
            }
        }
    }
    printf("Top %d possible plaintexts:\n", top_n);
    for (int i = 0; i < top_n && i < 26; i++) {
        printf("%2d. Shift %2d (score: %6.2f): %s\n", 
              i+1, attempts[i].shift, attempts[i].score, attempts[i].plaintext);
    }
    for (int i = 0; i < 26; i++) {
        free(attempts[i].plaintext);
    }
}

int main() {
    char ciphertext[1024];
    int top_n;
    
    printf("Enter ciphertext: ");
    fgets(ciphertext, sizeof(ciphertext), stdin);
    ciphertext[strcspn(ciphertext, "\n")] = '\0'; 
    
    printf("How many top results to show? ");
    scanf("%d", &top_n);
    
    if (top_n < 1 || top_n > 26) {
        printf("Invalid number. Showing top 5 results.\n");
        top_n = 5;
    }
    
    frequency_attack(ciphertext, top_n);
    return 0;
}
