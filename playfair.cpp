#include <stdio.h>
#include <string.h>
#include <ctype.h>

char matrix[5][5];

void createMatrix(char key[]) {
    int used[26] = {0};
    int i, j, k = 0;

    for (i = 0; key[i] != '\0'; i++) {
        char ch = toupper(key[i]);
        if (ch == 'J') ch = 'I';
        if (!isalpha(ch)) continue;
        if (!used[ch - 'A']) {
            matrix[k / 5][k % 5] = ch;
            used[ch - 'A'] = 1;
            k++;
        }
    }

    for (char ch = 'A'; ch <= 'Z'; ch++) {
        if (ch == 'J') continue;
        if (!used[ch - 'A']) {
            matrix[k / 5][k % 5] = ch;
            used[ch - 'A'] = 1;
            k++;
        }
    }
}
void findPos(char ch, int *row, int *col) {
    if (ch == 'J') ch = 'I';
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            if (matrix[i][j] == ch) {
                *row = i;
                *col = j;
                return;
            }
}
void encryptPair(char a, char b) {
    int r1, c1, r2, c2;
    findPos(a, &r1, &c1);
    findPos(b, &r2, &c2);

    if (r1 == r2) {
        printf("%c%c", matrix[r1][(c1 + 1) % 5], matrix[r2][(c2 + 1) % 5]);
    } else if (c1 == c2) {
        printf("%c%c", matrix[(r1 + 1) % 5][c1], matrix[(r2 + 1) % 5][c2]);
    } else {
        printf("%c%c", matrix[r1][c2], matrix[r2][c1]);
    }
}

int main() {
    char key[50], text[100];
    int i;

    printf("Enter keyword: ");
    fgets(key, sizeof(key), stdin);

    printf("Enter plaintext: ");
    fgets(text, sizeof(text), stdin);

    createMatrix(key);

    int len = 0;
    char clean[100];
    for (i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            clean[len++] = toupper(text[i] == 'J' ? 'I' : text[i]);
        }
    }
    clean[len] = '\0';

    char final[100];
    int k = 0;
    for (i = 0; i < len; i++) {
        final[k++] = clean[i];
        if (i + 1 < len && clean[i] == clean[i + 1]) {
            final[k++] = 'X';
        }
    }
    if (k % 2 != 0) final[k++] = 'X';
    final[k] = '\0';
    printf("Encrypted text: ");
    for (i = 0; i < k; i += 2) {
        encryptPair(final[i], final[i + 1]);
    }

    printf("\n");
    return 0;
}
