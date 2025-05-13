#include <stdio.h>

int main() {
    char message[100], encrypted[100];
    char key[27] = "QWERTYUIOPASDFGHJKLZXCVBNM";  
    int i;

    printf("Enter a message: ");
    fgets(message, sizeof(message), stdin); 

    for (i = 0; message[i] != '\0'; i++) {
        char ch = message[i];

        if (ch >= 'A' && ch <= 'Z') {
            encrypted[i] = key[ch - 'A'];
        }
        else if (ch >= 'a' && ch <= 'z') {
            encrypted[i] = key[ch - 'a'] + 32;  
        }
        
        else {
            encrypted[i] = ch;
        }
    }

    encrypted[i] = '\0';  

    printf("Encrypted message: %s\n", encrypted);

    return 0;
}

