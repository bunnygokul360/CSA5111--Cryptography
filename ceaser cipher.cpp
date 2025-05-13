#include <stdio.h>

int main() {
    char text[100];  
    int key, choice; 

    printf("Enter a message: ");
    fgets(text, sizeof(text), stdin);  
    printf("Enter the key (1-25): ");
    scanf("%d", &key);

    printf("Choose an option:\n1. Encrypt\n2. Decrypt\n");
    scanf("%d", &choice);

    for (int i = 0; text[i] != '\0'; i++) {
        char ch = text[i];

        if (ch >= 'A' && ch <= 'Z') {
            if (choice == 1)
                ch = ((ch - 'A' + key) % 26) + 'A';
            else if (choice == 2)
                ch = ((ch - 'A' - key + 26) % 26) + 'A';  
            text[i] = ch;
        }
        else if (ch >= 'a' && ch <= 'z') {
            if (choice == 1)
                ch = ((ch - 'a' + key) % 26) + 'a';
            else if (choice == 2)
                ch = ((ch - 'a' - key + 26) % 26) + 'a';
            text[i] = ch;
        }
    }

    if (choice == 1)
        printf("Encrypted message: %s\n", text);
    else if (choice == 2)
        printf("Decrypted message: %s\n", text);
    else
        printf("Invalid choice.\n");

    return 0;
}

