#include <stdio.h>
#include <string.h>
#include <ctype.h>
void matrixMultiply(int key[2][2], int *vector, int *result) {
    result[0] = (key[0][0] * vector[0] + key[0][1] * vector[1]) % 26;
    result[1] = (key[1][0] * vector[0] + key[1][1] * vector[1]) % 26;
    
    if(result[0] < 0) result[0] += 26;
    if(result[1] < 0) result[1] += 26;
}
int modInverse(int a, int m) {
    a = a % m;
    for(int x = 1; x < m; x++) {
        if((a * x) % m == 1) {
            return x;
        }
    }
    return -1;
}
void inverseMatrix(int key[2][2], int inv[2][2]) {
    int det = (key[0][0] * key[1][1] - key[0][1] * key[1][0]) % 26;
    if(det < 0) det += 26;
    
    int detInv = modInverse(det, 26);
    
    inv[0][0] = (key[1][1] * detInv) % 26;
    inv[0][1] = (-key[0][1] * detInv) % 26;
    inv[1][0] = (-key[1][0] * detInv) % 26;
    inv[1][1] = (key[0][0] * detInv) % 26;
    
    if(inv[0][1] < 0) inv[0][1] += 26;
    if(inv[1][0] < 0) inv[1][0] += 26;
}

void encryptHill(const char *plaintext, int key[2][2], char *ciphertext) {
    int len = strlen(plaintext);
    if(len % 2 != 0) len++; 
    
    for(int i = 0; i < len; i += 2) {
        int vector[2];
        vector[0] = toupper(plaintext[i]) - 'A';
        vector[1] = (i+1 < strlen(plaintext)) ? toupper(plaintext[i+1]) - 'A' : 'X' - 'A';
        
        int result[2];
        matrixMultiply(key, vector, result);
        
        ciphertext[i] = result[0] + 'A';
        ciphertext[i+1] = result[1] + 'A';
    }
    ciphertext[len] = '\0';
}

void decryptHill(const char *ciphertext, int key[2][2], char *plaintext) {
    int inv[2][2];
    inverseMatrix(key, inv);
    
    int len = strlen(ciphertext);
    
    for(int i = 0; i < len; i += 2) {
        int vector[2];
        vector[0] = toupper(ciphertext[i]) - 'A';
        vector[1] = toupper(ciphertext[i+1]) - 'A';
        
        int result[2];
        matrixMultiply(inv, vector, result);
        
        plaintext[i] = result[0] + 'A';
        plaintext[i+1] = result[1] + 'A';
    }
    plaintext[len] = '\0';
}

int main() {
    int key[2][2] = {{9, 4}, {5, 7}};
    const char *plaintext = "meet me at the usual place at ten rather than eight o clock";
    char ciphertext[1000];
    char decrypted[1000];
    char cleaned[1000];
    int pos = 0;
    for(int i = 0; plaintext[i]; i++) {
        if(isalpha(plaintext[i])) {
            cleaned[pos++] = tolower(plaintext[i]);
        }
    }
    cleaned[pos] = '\0';
    
    encryptHill(cleaned, key, ciphertext);
    printf("Encrypted message:\n%s\n", ciphertext);
    
    decryptHill(ciphertext, key, decrypted);
    printf("Decrypted message:\n%s\n", decrypted);
    
    return 0;
}
