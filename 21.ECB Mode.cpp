#include <stdio.h>

void ECB(char *plaintext, char key) {
    printf("ECB Encryption: ");
    for (int i = 0; plaintext[i] != '\0'; i++) {
        printf("%c", plaintext[i] ^ key);  
    }
    printf("\n");
}

int main() {
    char text[] = "HELLO";
    char key = 0x0F; 
    ECB(text, key);
    return 0;
}

