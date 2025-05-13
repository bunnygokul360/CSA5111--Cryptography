#include <stdio.h>

int main() {
    char plaintext[] = "hello";
    char ciphertext[100];
    int a = 5, b = 8;
    int i;

    printf("Plaintext: %s\n", plaintext);

    for (i = 0; plaintext[i] != '\0'; i++) {
        char ch = plaintext[i];
        if (ch >= 'a' && ch <= 'z') {
            ciphertext[i] = ((a * (ch - 'a') + b) % 26) + 'A'; 
        } else {
            ciphertext[i] = ch;
        }
    }
    ciphertext[i] = '\0';

    printf("Ciphertext: %s\n", ciphertext);

    return 0;
}

