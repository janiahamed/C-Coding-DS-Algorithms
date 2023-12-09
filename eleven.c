#include<stdio.h>
#define WARN_IF(EXP)  \
do {  \
    x--; \
    if (EXP) \
    {        \
        fprintf(stderr,"Warning: " #EXP "\n"); \
    } \
    else \
    { \
        fprintf(stderr, "No"); \
    } \
                } while(x);


void main() {
int x= 5;
WARN_IF(x==0);
}
