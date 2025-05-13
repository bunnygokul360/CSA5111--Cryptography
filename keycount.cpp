#include <stdio.h>
#include <math.h>

int main() {
    double totalPossible = 1;
    for(int i = 25; i > 0; i--) {
        totalPossible *= i;
    }
    
    printf("Total possible keys: ~2^%.0f\n", log2(totalPossible));
    
    printf("Effectively unique keys: ~2^44\n");
    
    return 0;
}
