#include <stdio.h>

void CTR_encrypt(char *plaintext, char key) {
    printf("CTR Encryption: ");
    for (int i = 0; plaintext[i] != '\0'; i++) {
        char counter = i;
        char keystream = counter ^ key;
        printf("%c", plaintext[i] ^ keystream);
    }
    printf("\n");
}

int main() {
    char text[] = "HELLO";
    char key = 0x0F;
    CTR_encrypt(text, key);
    return 0;
}

