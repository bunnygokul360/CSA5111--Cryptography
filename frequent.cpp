#include <stdio.h>

int main() {
    char text[] = "UBBBUUUBBBUUBUUBUUBBUBUUBBB"; 
    int freq[26] = {0};
    int i;

    for (i = 0; text[i] != '\0'; i++) {
        char ch = text[i];
        if (ch >= 'A' && ch <= 'Z') {
            freq[ch - 'A']++;
        }
    }

    for (i = 0; i < 26; i++) {
        printf("%c : %d\n", 'A' + i, freq[i]);
    }

    return 0;
}

