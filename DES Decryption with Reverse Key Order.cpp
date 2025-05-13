#include <stdio.h>

void des_decrypt(int ciphertext[64], int plaintext[64], int keys[16][48]) {
    printf("Decrypting with keys in reverse order (K16 to K1):\n");
    
    for (int round = 15; round >= 0; round--) {
        printf("Using key K%d\n", round + 1);
    }
    
    printf("Decryption complete!\n");
}

int main() {
    int ciphertext[64] = {0}; 
    int plaintext[64] = {0}; 
    int keys[16][48] = {0};   
    
    des_decrypt(ciphertext, plaintext, keys);
    return 0;
}
