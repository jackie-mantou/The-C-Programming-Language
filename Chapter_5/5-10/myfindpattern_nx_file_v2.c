#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>      /* for getopt */
#define  MAXSIZE   100
#define  OPTSTRING "nx"  /* for getopt */ 

/* find -n -x pattern <file>, file version 2 */

int main(int argc, char *argv[])
{
    int c;
    int number, except;
    char *lineptr;
    size_t lsize;
    int lnum;      /* line's number */
    char pattern[MAXSIZE] = "";
    FILE *fp;

    number = 0;
    except = 0;
    lineptr = NULL;
    lsize = 0;
    lnum = 0;

    /* process options */
    /* int getopt(int argc, char *argv[], const char *optstring) */
    while ((c = getopt(argc, argv, OPTSTRING)) != -1) {
        switch (c) {
            case 'n':
                number = 1;
                break;

            case 'x':
                except = 1;
                break;

            default:  /* '?' */
                fprintf(stderr, "Invalid argument -%c!\n", c);
                exit(EXIT_FAILURE);
        }
    }

    strcpy(pattern, argv[optind]);   /* get pattern */

    /* determine stdin or specified file */
    if (argc == 1) {
        printf("No specified file, read lines from standard input\n");
        fp = stdin;

        /* process pattern */
        while (getline(&lineptr, &lsize, fp) > 0) {
            lnum++;   /* record lines number */
            if ((strstr(lineptr, pattern) != NULL) != except) {
                if (number == 1)
                    printf("%d:", lnum);
                printf("%s", lineptr);
            }
        }
    }
    else
        while (argc-- > 0 && (fp = fopen(argv[++optind], "r")) != NULL) { /* open file */
            lnum = 0;  /* clear line number in next file */

            /* process pattern */
            while (getline(&lineptr, &lsize, fp) > 0) {
                lnum++;   /* record lines number */
                if ((strstr(lineptr, pattern) != NULL) != except) {
                    printf("%s:", argv[optind]);  /* print file name */
                    if (number == 1)
                        printf("line %d: ", lnum);
                    printf("%s", lineptr);
                }
            }
            fclose(fp);   /* close file */
        }

    free(lineptr);   /* free lineptr */

    exit(EXIT_SUCCESS);
}
