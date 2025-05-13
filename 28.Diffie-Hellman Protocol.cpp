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
    long q, a; 
    printf("Enter prime q and base a: ");
    scanf("%ld %ld", &q, &a);
    
    printf("\nOriginal Diffie-Hellman:\n");
    long xA = rand() % (q-1) + 1; 
    long xB = rand() % (q-1) + 1; 
    
    long yA = mod_exp(a, xA, q); 
    long yB = mod_exp(a, xB, q);
    
    long kA = mod_exp(yB, xA, q);
    long kB = mod_exp(yA, xB, q);
    
    printf("Shared key (original): %ld\n", kA);
    
    printf("\nModified (insecure) version:\n");
    yA = mod_exp(xA, a, q); 
    yB = mod_exp(xB, a, q); 
    printf("No way to compute shared key from xA^a and xB^a!\n");
    
    printf("\nAlternative method:\n");
    long new_base = rand() % (q-1) + 1;
    yA = mod_exp(new_base, xA, q);
    yB = mod_exp(new_base, xB, q);
    
    kA = mod_exp(yB, xA, q);
    kB = mod_exp(yA, xB, q);
    printf("Shared key (alternative): %ld\n", kA);
    
    printf("\nEve can break the modified system by:\n");
    printf("1. Computing discrete logarithm to find xA or xB\n");
    printf("2. If a is small, brute force is possible\n");
    
    return 0;
}
