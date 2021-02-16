#include <stdio.h>

/* echo command-line arguments. Version 1 */

int main(int argc, char *argv[])
{
    int i;

    /* command-line arguments is argv[1] ~ argv[argc-1] */
    for (i = 1; i < argc; ++i)
        printf("%s%s", argv[i], (i < argc-1) ? " " : "");
    printf("\n");

    return 0;
}
