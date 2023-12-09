#include<stdio.h>
void print_arr(int a[], int *b) {
    int *ptr = b;
    for (int i = 0 ; i < 5; i++) {
        printf("\n%d:%d",a[i], *(ptr)++);
    }
}
int* modify(int *arr) {
    int *ptr = arr;
    for (int i = 0; i < 5; i++) {
        *(arr+i) += 10;
    }
    return arr;
}
int *ret_arr() {
    static int fd[5] = {56,65,43,34,21};
    return fd;
}
void main() {
    int a[5] = {11,12,13,14,15};
    int *ptr;
    ptr = a;
    for (int i = 0; i < 5; i++) {
        printf("\n%u ",&a[i]);
        printf("\n%u ",*(ptr+i));
    }
    printf("\nSize of array is : %d",sizeof(a)/sizeof(a[0]));
    int ra[] = {1, 2, 3, 4, 5};
    int ew[5] = {4,6};
    memcpy(ew,ra,sizeof(ew));
    printf("\nSize of array is : %d",sizeof(ew));
    for (int i = 0 ; i < 5; i ++) {
        printf("\n%d",ew[i]);
    }
    print_arr(a,ew);
    int *qq = modify(a);
    int *po = ret_arr();
    print_arr(po,ew);
    print_arr(ew,qq);
}
