#include <stdio.h>
#include <stdlib.h>

int main() {
    char number;
    printf("\nEnter something: ");
    scanf("%c", &number);
    printf("\ninput is : %c", number);

    int asciiValue = number;

    printf("\nThe input is : %d", asciiValue);

    switch (asciiValue) {
        case 48 ... 57:
            printf("\nNumber!");
            break;
        case 65 ... 90:
            printf("\nAlphabet! (Upper case)");
            break;
        case 97 ... 122:
            printf("\nAlphabet! (Lower case)");
            break;
        default:
            printf("\nCould be symbols or special characters!");
    }

    return 0;
}

