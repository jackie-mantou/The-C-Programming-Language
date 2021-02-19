#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* find -n -x pattern, stdin version */

int main(int argc, char *argv[])
{
    int c;
    int number, except;
    char *lineptr;
    size_t lsize;
    int lnum;

    number = 0;
    except = 0;
    lineptr = NULL;
    lsize = 0;
    lnum = 0;

    /* process '-n', '-x', '-nx', '-xn' */
    while (--argc > 0 && (*++argv)[0] == '-')
        while ((c = *++argv[0]) != '\0') {
            switch (c) {
                case 'n':
                    number = 1;
                    break;

                case 'x':
                    except = 1;
                    break;

                default:
                    fprintf(stderr, "Invalid argument -%c!\n", c);
                    break;
            }
        }

    /* judge usage */
    if (argc != 1) {
        fprintf(stderr, "Usage: ./a.out -n -x pattern\n");
        return -1;
    }

    /* process pattern */
    while (getline(&lineptr, &lsize, stdin) > 0) {
        if ((strstr(lineptr, *argv) != NULL) != except) {
            if (number == 1)
                printf("line %d: ", ++lnum);
            printf("%s", lineptr);
        }
    }

    /* free lineptr */
    free(lineptr);

    return 0;
}
