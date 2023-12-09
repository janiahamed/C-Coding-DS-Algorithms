#include<stdio.h>
void call(int *addr, int count) {
    for (int i = 0; i < count; i++)
        for (int j = 0; j < count; j++)
            printf("\n%d:",*(addr+i)+j);
}
void main() {
    int *ptr[3];
    int a = 0;
    int b = 100;
    int c = 4000;
    ptr[0] = &a;
    ptr[1] = &b;
    ptr[2] = &c;
    //call(&a);
    int arr[2][2] = {{101,201},
                    {303,403}};
    call(arr,2);
}
