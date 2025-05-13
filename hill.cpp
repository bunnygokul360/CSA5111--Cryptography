#include <stdio.h>
#include <string.h>

void hill_attack(const char *plain, const char *cipher, int block_size) {
    printf("Performing known plaintext attack on Hill cipher...\n");
    printf("Given plaintext:  %s\n", plain);
    printf("Given ciphertext: %s\n", cipher);
    printf("Assuming block size: %d\n", block_size);
    
    printf("\nSteps to recover key:\n");
    printf("1. Create %dx%d matrices from plaintext and ciphertext blocks\n", block_size, block_size);
    printf("2. Set up matrix equation: Cipher = Key × Plaintext\n");
    printf("3. Solve for Key matrix using matrix inversion\n");
    printf("4. Verify recovered key with additional plaintext-ciphertext pairs\n");
}

int main() {
    const char *plain = "attack";
    const char *cipher = "PQCFKU";
    hill_attack(plain, cipher, 2);
    return 0;
}
