#include <stdio.h>

/* echo command-line arguments. Version 2 */ 

int main(int argc, char *argv[])
{
    /* command-line arguments: argv[1] ~ argv[argc-1] */
    while (--argc)
        printf("%s%s", *++argv, argc > 1 ? " " : "");
    printf("\n");

    return 0;
}
