#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long gcd(long a, long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    long n, e, c;
    printf("Enter modulus n: ");
    scanf("%ld", &n);
    printf("Enter public exponent e: ");
    scanf("%ld", &e);
    printf("Enter ciphertext c: ");
    scanf("%ld", &c);
    
    
    long result = 1;
    for (long i = 0; i < e; i++) {
        result = (result * c) % n;
    }
    
    long factor = gcd(result, n);
    
    if (factor > 1 && factor < n) {
        printf("Factor of n found: %ld\n", factor);
        printf("This allows factorization of n and breaking the RSA!\n");
        printf("Other factor: %ld\n", n / factor);
    } else {
        printf("No common factor found between plaintext and n\n");
    }
    
    return 0;
}
