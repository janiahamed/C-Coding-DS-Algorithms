#include <stdio.h>

#pragma pack(1)

struct ExampleStruct {
    char a;
    int b;
    char c;
};

#pragma pack()

struct sExampleStruct {
    char a;
    int b;
    char c;
};

typedef enum{
    i = 0,
    j,
    k,
    l = 5,
    m,
    n
} Values;
int main() {
    printf("Size of ExampleStruct: %zu bytes\n", sizeof(struct ExampleStruct));
    printf("Size of sExampleStruct: %zu bytes\n", sizeof(struct sExampleStruct));
    Values a = j;
    printf("\n%d",a);
    return 0;
}

