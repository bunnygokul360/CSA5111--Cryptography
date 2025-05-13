#include <stdio.h>

int main() {
    char plaintext[] = "attack";
    char ciphertext[100];
    char key[] = "CIPHERABDFGJKLMNOQSTUVWXYZ";
    int i;

    for (i = 0; plaintext[i] != '\0'; i++) {
        char ch = plaintext[i];
        if (ch >= 'a' && ch <= 'z') {
            ciphertext[i] = key[ch - 'a'];
        } else {
            ciphertext[i] = ch;
        }
    }
    ciphertext[i] = '\0';

    printf("Ciphertext: %s\n", ciphertext);

    return 0;
}

