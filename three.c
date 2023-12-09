#include<stdio.h>
#include<stdlib.h>
int main(int argc, char *argv[]) {
    int iter = atoi(argv[1]);
    int i = 0;
     for(i = 0; i < iter; i++) {
         if (i == 5) continue;
         if (i == 8) break;
        printf("\n%d",i);
     }
}
