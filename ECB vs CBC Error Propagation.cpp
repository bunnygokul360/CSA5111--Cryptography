#include <stdio.h>

void ecb_decrypt(int ciphertext[][8], int plaintext[][8], int blocks) {
    printf("ECB Mode - Each block decrypted independently:\n");
    for (int i = 0; i < blocks; i++) {
        printf("  Decrypting block %d\n", i + 1);
    }
}

void cbc_decrypt(int ciphertext[][8], int plaintext[][8], int blocks, int iv[8]) {
    printf("CBC Mode - Error propagates to next block:\n");
    for (int i = 0; i < blocks; i++) {
        printf("  Decrypting block %d\n", i + 1);
        if (i == 0) printf("    Error here will affect block 1 and 2\n");
    }
}

int main() {
    int ciphertext[3][8] = {0};
    int plaintext[3][8] = {0};
    int iv[8] = {0};
    
    ecb_decrypt(ciphertext, plaintext, 3);
    printf("\n");
    cbc_decrypt(ciphertext, plaintext, 3, iv);
    
    printf("\nAnswers:\n");
    printf("a. In CBC, blocks beyond P2 are NOT affected by error in C1\n");
    printf("b. Error in P1 propagates to ALL subsequent ciphertext blocks\n");
    
    return 0;
}
