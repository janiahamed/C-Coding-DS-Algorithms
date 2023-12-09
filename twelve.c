#include<stdio.h>
typedef struct name {
    char *first;
    char *last;
} name_t;
void main() {
    name_t n;
    name_t m;
    n.first=malloc(20);
    n.last=malloc(20);
    strcpy(n.first,"kou");
    strcpy(n.last,"jiim");
    printf("%s %s",n.first,n.last);
    m = n;
    printf("%s %s",m.first,m.last);
    strcpy(m.first,"change");
    printf("%s %s",n.first,n.last);
    printf("%s %s",m.first,m.last);
    name_t *ptr = &n;
    printf("\n%s : %s",ptr->first,ptr->last);

}
