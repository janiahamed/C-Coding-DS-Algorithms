#include<stdio.h>
void main(int argc, char *argv[]) {
    int number = atoi(argv[1]);
    printf("\nThe input is : %d %s", number, argv[1]);
    if (number >= 48 && number <= 58) {
        printf("\nNumber!");
    } else if (number >= 65 && number <= 90) {
        printf("\nUpper case Alphabet!");
    } else if (number >= 97 && number <= 122) {
        printf("\nLower case Alphabet!");
    } else {
        printf("\nCould be symbols or special characters!");
    }
    return;
}
