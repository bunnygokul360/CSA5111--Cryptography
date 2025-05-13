#include <stdio.h>
#include <string.h>
#include <ctype.h>

void createPlayfairMatrix(char matrix[5][5], const char *key) {
    
    const char *matrixData = "MFHIJKUNOPQZVWXYELARGDSTBC";
    int pos = 0;
    
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            matrix[i][j] = matrixData[pos++];
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

void decryptPlayfair(char matrix[5][5], const char *ciphertext, char *plaintext) {
    int len = strlen(ciphertext);
    int pos = 0;
    
    for(int i = 0; i < len; i += 2) {
        char a = toupper(ciphertext[i]);
        char b = toupper(ciphertext[i+1]);
        
        int rowA, colA, rowB, colB;
        findPosition(matrix, a, &rowA, &colA);
        findPosition(matrix, b, &rowB, &colB);
        
        if(rowA == rowB) {
          
            plaintext[pos++] = matrix[rowA][(colA - 1 + 5) % 5];
            plaintext[pos++] = matrix[rowB][(colB - 1 + 5) % 5];
        } else if(colA == colB) {
          
            plaintext[pos++] = matrix[(rowA - 1 + 5) % 5][colA];
            plaintext[pos++] = matrix[(rowB - 1 + 5) % 5][colB];
        } else {
            plaintext[pos++] = matrix[rowA][colB];
            plaintext[pos++] = matrix[rowB][colA];
        }
    }
    plaintext[pos] = '\0';
}

int main() {
    char matrix[5][5];
    const char *ciphertext = "KXJEYUREBEZWEHEWRYTUHEYESKREHEGOYFIWTTIUOLKSYCAIPOBOTEIZONTXBYBNTGONEYCUZWRGDSONSXBOUYWRIEBAAHYUSEDQ";
    char plaintext[1000];
    
    createPlayfairMatrix(matrix, "EXAMPLE"); 
    decryptPlayfair(matrix, ciphertext, plaintext);
    
    printf("Decrypted message:\n%s\n", plaintext);
    
    return 0;
}
