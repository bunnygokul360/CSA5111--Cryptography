#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long mod_exp(long base, long exp, long mod) {
    long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp = exp / 2;
    }
    return result;
}

int main() {
    long n, e;
    printf("Enter modulus n: ");
    scanf("%ld", &n);
    printf("Enter public exponent e: ");
    scanf("%ld", &e);
    
    printf("Enter message characters as numbers (0-25), end with -1:\n");
    
    long m;
    while (1) {
        scanf("%ld", &m);
        if (m == -1) break;
        if (m < 0 || m > 25) {
            printf("Invalid input (0-25 only)\n");
            continue;
        }
        
        long c = mod_exp(m, e, n);
        printf("Plaintext: %ld, Ciphertext: %ld\n", m, c);
    }
    
    printf("\nSecurity Warning:\n");
    printf("Encrypting small values (0-25) separately is vulnerable to:\n");
    printf("1. Brute force attack (only 26 possible values per character)\n");
    printf("2. Frequency analysis (matching ciphertext frequencies to plaintext)\n");
    
    return 0;
}
