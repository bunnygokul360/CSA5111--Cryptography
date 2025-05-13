#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long gcd(long a, long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

long mod_inverse(long e, long phi) {
    for (long d = 1; d < phi; d++) {
        if ((e * d) % phi == 1) {
            return d;
        }
    }
    return -1; 
}

int main() {
    long p, q, n, phi, e, d;
    
    printf("Enter primes p and q: ");
    scanf("%ld %ld", &p, &q);
    
    n = p * q;
    phi = (p-1) * (q-1);
    
    printf("Original modulus n: %ld\n", n);
    printf("Original phi(n): %ld\n", phi);
    
    e = 65537; 
    d = mod_inverse(e, phi);
    printf("Original private key d: %ld\n", d);
    
    long new_e;
    do {
        new_e = rand() % (phi - 2) + 2; 
    } while (gcd(new_e, phi) != 1);
    
    long new_d = mod_inverse(new_e, phi);
    
    printf("\nNew public key e: %ld\n", new_e);
    printf("New private key d: %ld\n", new_d);
    
    printf("\nWarning: Using same modulus n with new keys is NOT safe!\n");
    printf("An attacker can use both key pairs to factor n and break the system.\n");
    
    return 0;
}
