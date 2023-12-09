#include<stdio.h>
#include<stdarg.h>
int add(int count, ...) {
    va_list ap;
    int sum = 0;
    va_start(ap, count);
    for (int i = 0; i < count; i++) {
        sum += va_arg(ap, int);
    }
    va_end(ap);
    return sum;
}
int main() {
   int  j = 0x1234567;
   int sum = add(5,1,2,3,4,5);
   printf("%d",sum);
   char *ptr = (char *)&j;
   for (int i = 0; i < sizeof(i); i++)
   printf("\n%d: %x",sizeof(i),*(ptr+i));
   *(ptr+2) = 0x88;
   printf("\n%x",j);
   int arr[2] = {11,12};
   printf("\n%d:%d",arr[0],1[arr]);
   return 0;
}
