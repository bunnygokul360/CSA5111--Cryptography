#include <stdio.h>

int main() {
    char cipher[] = "J8;:*+8t83(88)5*+;46(88*%?8)*(;485);5*+2:*;(4956*2(5*-4)8¶18*;4069285;)6t)84+;(†9;48081;8+81;4t85;4)485t528806*81(9;48;(4†33t;48)4†;161;188;+?;";
    int freq[128] = {0};

    for (int i = 0; cipher[i] != '\0'; i++) {
        freq[(int)cipher[i]]++;
    }

    for (int i = 0; i < 128; i++) {
        if (freq[i] > 0) {
            printf("'%c' : %d\n", i, freq[i]);
        }
    }

    return 0;
}

