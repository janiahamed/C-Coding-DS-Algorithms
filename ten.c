#include <stdio.h>
#include <string.h>

void main()
{
char str[50] = "I@Like@To@Play@Football";

// Returns the first token
char* token = strtok(str, "@");

// Keeps printing the token till the token is not NULL.
    
while (token != NULL) 
{
    printf("%s ", token);
    token = strtok(NULL, "@");
}
    
}
