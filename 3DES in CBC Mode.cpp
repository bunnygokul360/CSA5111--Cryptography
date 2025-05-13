#include <stdio.h>
#include <string.h>

void xor_blocks(int block1[8], int block2[8], int result[8]) {
    for (int i = 0; i < 8; i++) {
        result[i] = block1[i] ^ block2[i];
    }
}

void triple_des_cbc(int plaintext[][8], int ciphertext[][8], int blocks, int key1, int key2, int key3, int iv[8]) {
    int previous[8];
    memcpy(previous, iv, 8 * sizeof(int));
    
    for (int i = 0; i < blocks; i++) {
        printf("Block %d:\n", i + 1);
        xor_blocks(plaintext[i], previous, plaintext[i]);
        
        printf("  Encrypting with 3DES (E-D-E)\n");
       
        memcpy(ciphertext[i], plaintext[i], 8 * sizeof(int));
        memcpy(previous, ciphertext[i], 8 * sizeof(int));
    }
}

int main() {
    int plaintext[2][8] = {{1,2,3,4,5,6,7,8}, {9,8,7,6,5,4,3,2}};
    int ciphertext[2][8];
    int iv[8] = {0};
    
    triple_des_cbc(plaintext, ciphertext, 2, 123, 456, 789, iv);
    
    printf("\nWhich to choose?\n");
    printf("a. For security: 3DES (more secure)\n");
    printf("b. For performance: DES (faster)\n");
    
    return 0;
}
