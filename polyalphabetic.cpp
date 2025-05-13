#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char plaintext[100], key[100], ciphertext[100];
    int i, j = 0;

    printf("Enter plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0'; 

    printf("Enter key: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = '\0';  

    for (i = 0; plaintext[i] != '\0'; i++) {
        char ch = plaintext[i];

        if (isalpha(ch)) {  
            int shift = toupper(key[j % strlen(key)]) - 'A';

            if (isupper(ch)) {
                ciphertext[i] = (ch - 'A' + shift) % 26 + 'A';
            }
            else {
                ciphertext[i] = (ch - 'a' + shift) % 26 + 'a';
            }

            j++;  
        } else {
            ciphertext[i] = ch;  
        }
    }

    ciphertext[i] = '\0';  
    printf("Encrypted message: %s\n", ciphertext);

    return 0;
}

