#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

const char *ENGLISH_ORDER = "etaoinshrdlcumwfgypbvkjxqz";

typedef struct {
    char letter;
    int count;
} CharFrequency;

int compare_freq(const void *a, const void *b) {
    return ((CharFrequency *)b)->count - ((CharFrequency *)a)->count;
}

void substitution_attack(const char *ciphertext) {
    CharFrequency freq[26] = {0};
    int total_letters = 0;
    
    for (int i = 0; i < 26; i++) {
        freq[i].letter = 'a' + i;
        freq[i].count = 0;
    }
    
    for (int i = 0; ciphertext[i]; i++) {
        if (isalpha(ciphertext[i])) {
            freq[tolower(ciphertext[i]) - 'a'].count++;
            total_letters++;
        }
    }
    qsort(freq, 26, sizeof(CharFrequency), compare_freq);
    
    char mapping[26];
    for (int i = 0; i < 26; i++) {
        mapping[freq[i].letter - 'a'] = (i < strlen(ENGLISH_ORDER)) ? ENGLISH_ORDER[i] : '?';
    }
    size_t text_len = strlen(ciphertext);
    char *plaintext = (char *)malloc(text_len + 1);
    if (!plaintext) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }
    for (size_t i = 0; i < text_len; i++) {
        if (isalpha(ciphertext[i])) {
            char base = islower(ciphertext[i]) ? 'a' : 'A';
            plaintext[i] = mapping[tolower(ciphertext[i]) - 'a'];
            if (isupper(ciphertext[i])) {
                plaintext[i] = toupper(plaintext[i]);
            }
        } else {
            plaintext[i] = ciphertext[i];
        }
    }
    plaintext[text_len] = '\0';
    
    printf("Decrypted text: %s\n", plaintext);
    free(plaintext);
}

int main() {
    char ciphertext[1024];
    
    printf("Enter ciphertext: ");
    if (!fgets(ciphertext, sizeof(ciphertext), stdin)) {
        fprintf(stderr, "Error reading input\n");
        return 1;
    }
    
    ciphertext[strcspn(ciphertext, "\n")] = '\0';
    
    substitution_attack(ciphertext);
    return 0;
}
