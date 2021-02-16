#include <stdio.h>

/* echo command-line arguments. Version 3 */ 

int main(int argc, char *argv[])
{
    /* command-line arguments: argv[1] ~ argv[argc-1] */
    while (--argc)
        printf((argc > 1) ? "%s " : "%s", *++argv);
    printf("\n");

    return 0;
}
