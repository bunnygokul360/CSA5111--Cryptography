#include <stdio.h>

void CBC_encrypt(char *plaintext, char key, char IV) {
    printf("CBC Encryption: ");
    char prev = IV;
    for (int i = 0; plaintext[i] != '\0'; i++) {
        char input = plaintext[i] ^ prev;
        char output = input ^ key;
        printf("%c", output);
        prev = output;
    }
    printf("\n");
}

int main() {
    char text[] = "HELLO";
    char key = 0x0F;
    char IV = 0x01;
    CBC_encrypt(text, key, IV);
    return 0;
}

