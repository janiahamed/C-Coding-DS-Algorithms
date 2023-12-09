#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char result[32] = "\0";
int count(int a) {
    int c = 0;
    for (int j = 0; j < 32; j++) {
        if (a & 1)
            c++;
        a >>= 1;
    }
    return c;
}
char *bits(int a) {
    for(int i = 31; i >=0; i--) {
        if (a & (1 << i)) {
            strcat(result,"1");
        } else {
            strcat(result,"0");
        }
    }
    return result;
}
char *swap_nibble(int a) {
    int lmask = 0xf0;
    int rmask = 0x0f;
    int left = a & lmask;
    int right = a & rmask;
    memset(result,"\0",sizeof(result));
    int res = right << 4;
    res |= (left >> 4);
    return bits(res);
    
}
char *swap_nibbles(int a) {
    memset(result, '\0', sizeof(result));

    // Swap the nibbles using bitwise operations
    int res = ((a & 0x0F) << 4) | ((a & 0xF0) >> 4);

    return bits(res);
}
int set_bit(int a, int b) {
    int c = 1 << b;
    a |= c;
    return a;
}
int get_bit(int a, int b) {
    int d = a;
    return d >> b;
}
int main(int argc, char *argv[]) {
    int i = atoi(argv[1]);
    printf("\nBit representation is : %s",bits(i));
    printf("\nNo of 1 bits : %d",count(i));
    printf("\nSwapped Nibble : %s",swap_nibble(i));
    printf("\nSwapped Nibbles : %s",swap_nibbles(i));
    printf("\nBit representation is : %s",bits(0x432));
    printf("\nBit representation is : %c",get_bit(0x432,13));
    int r = set_bit(0x432,13);
    printf("\nBit representation is : %s",bits(r));
    printf("\nBit got is : %d",get_bit(r,13));
}
