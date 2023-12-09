#include<stdio.h>
void main() {
    FILE *fp = fopen("thirteen.c", "r");
    FILE *fp1 = fopen("sample.txt","rw");
    if (fp == NULL) puts("Failed opening");
    else puts("Opened successfully!");

    char buffer[100];
    char buffer1[100];
    while (fscanf(fp, "%s", buffer) != EOF) {
        fprintf(fp1, "%s", buffer);
        fprintf(fp1,"%s","\n");
        puts(buffer);
    }
    fclose(fp);
    printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n\n\n");
    rewind(fp1);
    while(fscanf(fp1, "%s", buffer1) != EOF)
    puts(buffer1);
}
