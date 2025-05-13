#include <stdio.h>

void generate_split_keys(int master_key[64], int round_keys[16][48]) {
    printf("Generating keys with split subkeys:\n");
    
    for (int round = 0; round < 16; round++) {
        printf("Round %2d: First 24 bits from first half, next 24 from second half\n", round + 1);
    
    }
}

int main() {
    int master_key[64] = {0};  
    int round_keys[16][48] = {0}; 
    
    generate_split_keys(master_key, round_keys);
    return 0;
}
