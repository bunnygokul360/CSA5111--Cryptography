#include <stdio.h>
int gcdExtended(int a, int b, int *x, int *y) {
    if (a == 0) {
        *x = 0, *y = 1;
        return b;
    }
    int x1, y1;
    int gcd = gcdExtended(b % a, a, &x1, &y1);
    *x = y1 - (b / a) * x1;
    *y = x1;
    return gcd;
}

int modInverse(int e, int phi) {
    int x, y;
    int g = gcdExtended(e, phi, &x, &y);
    if (g != 1)
        return -1;
    else
        return (x % phi + phi) % phi;
}

int main() {
    int e = 31, n = 3599;
    int p = 59, q = 61; 
    int phi = (p - 1) * (q - 1);
    int d = modInverse(e, phi);
    printf("Private Key (d): %d\n", d);
    return 0;
}

