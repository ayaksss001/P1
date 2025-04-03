#include <stdio.h>
#include <string.h>

int name ()
{
    int c;
    char name[9];

    printf("Hello what is your name?\n");
    fgets(name, sizeof(name), stdin);

    if (name[strlen(name) - 1] == '\n')
    {
        name[strlen(name) - 1] = '\0';
    }
    
    printf("Do you want to play %s?\n", name);

}