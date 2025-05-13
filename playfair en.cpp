#include <stdio.h>
#include <string.h>
#include <ctype.h>

void createPlayfairMatrix(char matrix[5][5]) {

    const char *rows[] = {
        "MFHIJK",
        "UNOPQ",
        "ZVWXY",
        "ELARG",
        "DSTBC"
    };
    
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            matrix[i][j] = rows[i][j];
        }
    }
}

void findPosition(char matrix[5][5], char ch, int *row, int *col) {
    if(ch == 'J') ch = 'I'; 
    
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            if(matrix[i][j] == ch) {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}

void preparePlaintext(char *text) {
    int pos = 0;
    for(int i = 0; text[i]; i++) {
        if(isalpha(text[i])) {
            text[pos++] = toupper(text[i]);
        }
    }
    text[pos] = '\0';
    
    for(int i = 0; i < strlen(text) - 1; i += 2) {
        if(text[i] == text[i+1]) {
            memmove(&text[i+2], &text[i+1], strlen(text) - i);
            text[i+1] = 'X';
        }
    }
    
    if(strlen(text) % 2 != 0) {
        text[strlen(text)] = 'X';
        text[strlen(text)+1] = '\0';
    }
}

void encryptPlayfair(char matrix[5][5], const char *plaintext, char *ciphertext) {
    int len = strlen(plaintext);
    int pos = 0;
    
    for(int i = 0; i < len; i += 2) {
        char a = plaintext[i];
        char b = plaintext[i+1];
        
        int rowA, colA, rowB, colB;
        findPosition(matrix, a, &rowA, &colA);
        findPosition(matrix, b, &rowB, &colB);
        
        if(rowA == rowB) {
          
            ciphertext[pos++] = matrix[rowA][(colA + 1) % 5];
            ciphertext[pos++] = matrix[rowB][(colB + 1) % 5];
        } else if(colA == colB) {
            
            ciphertext[pos++] = matrix[(rowA + 1) % 5][colA];
            ciphertext[pos++] = matrix[(rowB + 1) % 5][colB];
        } else {
            
            ciphertext[pos++] = matrix[rowA][colB];
            ciphertext[pos++] = matrix[rowB][colA];
        }
    }
    ciphertext[pos] = '\0';
}

int main() {
    char matrix[5][5];
    char plaintext[] = "Must see you over Cadogan West. Coming at once.";
    char ciphertext[1000];
    
    createPlayfairMatrix(matrix);
    preparePlaintext(plaintext);
    encryptPlayfair(matrix, plaintext, ciphertext);
    
    printf("Encrypted message:\n");
    for(int i = 0; ciphertext[i]; i++) {
        if(i > 0 && i % 5 == 0) printf(" ");
        printf("%c", ciphertext[i]);
    }
    printf("\n");
    
    return 0;
}
