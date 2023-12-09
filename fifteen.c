#include<stdio.h>
int add (int a, int b) {
     return a+b;
}
int subtract (int a, int b) {
    return a-b;
}
int multiply (int a, int b) {
    return a*b;
}
typedef int (*fptr[3]) (int, int);
void main(){
    int c = 0;
    fptr fpt = {add, subtract, multiply};
    int (*fp[3]) (int, int) = {add,subtract,multiply};
    printf("\n%d",fp[0](10,20));
    printf("\n%d",fp[1](10,20));
    printf("\n%d",fp[2](10,20));
    printf("\n%d",fpt[0](10,20));
    printf("\n%d",fpt[1](10,20));
    printf("\n%d",fpt[2](10,20));
}
