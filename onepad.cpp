#include <stdio.h>
#include <ctype.h>
#include <string.h>

void otp_encrypt(const char *plain, const int *key, char *cipher) {
    for (int i = 0; plain[i]; i++) {
        if (isalpha(plain[i])) {
            char base = islower(plain[i]) ? 'a' : 'A';
            cipher[i] = ((plain[i] - base + key[i]) % 26) + base;
        } else {
            cipher[i] = plain[i];
        }
    }
}

void otp_decrypt(const char *cipher, const int *key, char *plain) {
    for (int i = 0; cipher[i]; i++) {
        if (isalpha(cipher[i])) {
            char base = islower(cipher[i]) ? 'a' : 'A';
            plain[i] = ((cipher[i] - base - key[i] + 26) % 26) + base;
        } else {
            plain[i] = cipher[i];
        }
    }
}

void find_key(const char *cipher, const char *desired_plain, int *key) {
    for (int i = 0; cipher[i] && desired_plain[i]; i++) {
        if (isalpha(cipher[i]) && isalpha(desired_plain[i])) {
            char cipher_base = islower(cipher[i]) ? 'a' : 'A';
            char plain_base = islower(desired_plain[i]) ? 'a' : 'A';
            key[i] = ((cipher[i] - cipher_base) - (desired_plain[i] - plain_base) + 26) % 26;
        }
    }
}

int main() {
    const char *plain = "sendmoremoney";
    const int key[] = {9, 0, 1, 7, 23, 15, 21, 14, 11, 11, 2, 8, 9};
    char cipher[20] = {0};
    
    otp_encrypt(plain, key, cipher);
    printf("Original plaintext: %s\n", plain);
    printf("Encrypted ciphertext: %s\n", cipher);
    const char *desired_plain = "cashnotneeded";
    int new_key[20] = {0};
    
    find_key(cipher, desired_plain, new_key);
    printf("\nKey to decrypt to '%s':\n", desired_plain);
    for (int i = 0; i < strlen(desired_plain); i++) {
        printf("%d ", new_key[i]);
    }
    printf("\n");
    char result[20] = {0};
    otp_decrypt(cipher, new_key, result);
    printf("Decryption result: %s\n", result);
    
    return 0;
}
