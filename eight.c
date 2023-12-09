#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
void main() {
#if 0
    printf("\nEnter the number of iterations!"); 
    int iter = 0;
    scanf("%d",&iter);
    for (int i = 0; i < iter; i++) {
        printf("%d",i);
    }
    int ch = '\0';
    while ((ch = getchar()) != EOF) {
        putchar(ch);
    }
   puts("EOF"); 
   char *ab = "Allah";
   printf(ab);
   printf("\n%3d",10);
   printf("\n%3d",1000000000000);
   printf("\n%3d",1000000);
   printf("\n%3d",10000);
#endif
   char *ma = (char*)malloc(sizeof(100));
   sprintf(ma,"%s %d", "Allah", 100);
   printf("%s",ma);
   char who[20];
   int how = 0;
   sscanf(ma,"%s %d",who, &how);
   printf("%s %d",who,how);
   if (sizeof("Hello" "World") == (sizeof("Hello") + sizeof("World"))) {
       printf("yes");
   } else {
       printf("No");
   }
   printf("%d",sizeof("Hello" "World"));
   printf("%d",(sizeof("Hello") + sizeof("World")));

   char str1[6] = "Hello";
   char str4[6] = "Hello";
   char str2[6] = {'H', 'O', 'W'};
   char str3[6];
   strcpy(str3,"who");
   printf("\n%s %s %s",str1,str2,str3);
   char *str5 = "fas";
   char *str6 = "fas";
   if (str5 == str6) printf("\nEQUAL");
   else printf("\nNOT EQUAL");
}
