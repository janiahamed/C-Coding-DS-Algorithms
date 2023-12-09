#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
void main() {
  char *s = "ABC";
  char *d = "DEFABCREQ";
  char *c = strstr(d,s);
  printf("%c %c %c %c",*c,*(c+1),*(c+2),*(c+3));
   char mystr[] = "I'm an example of function strchr";
     printf ("%s", strchr(mystr, 'f'));
     char dd[50] = "sdsdsd";
     char ss[50]="12121";
     strcat(dd,ss);
     printf("%s",dd);

     char string[60] = "www @gmail @com";
     char sd[2] = "@";
     char *token;
     token = strtok(string,sd);
     while (token!=NULL) {
         printf("%s",token);
         token = strtok(NULL,sd);
     }
     printf("%s", token);
}
