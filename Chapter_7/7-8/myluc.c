#include <stdio.h>
#include <ctype.h>     /* for toupper() & tolower() */
#include <stdlib.h>    /* for exit */
#include <unistd.h>    /* for getopt */
#include <string.h>    /* for memset */
#define  OPTSTRING   "ul"
#define  MAXSIZE     100

/* convert content of file all to upper or lower;
 * -ul is equivalent to -l */

void fileconversion(FILE *ifp, FILE *ofp, int u2l, int l2u);

int main(int argc, char *argv[])
{
    int c, myargc;
    int u2l, l2u;
    FILE *fp;

    u2l = l2u = 0;

    /* command option process */
    while ((c = getopt(argc, argv, OPTSTRING)) != -1) {
        switch (c) {
            case 'u':
                l2u = 1;
                break;

            case 'l':
                u2l = 1;
                break;

            default:
                fprintf(stderr, "Usage: %s [-u] [-l] [files] ...\n", argv[0]);
                exit(EXIT_FAILURE);
        }
    }

    myargc = argc - optind + 1;
    if (myargc == 1)    /* read from stdin */
        fileconversion(stdin, stdout, u2l, l2u);
    else
        while (--myargc > 0)  /* read from files */
            if ((fp = fopen(argv[optind], "r")) == NULL) {
                fprintf(stderr, "%s can't open %s\n", argv[0], argv[optind]);
                exit(EXIT_FAILURE);
            }
            else {
                fileconversion(fp, stdout, u2l, l2u);
                fclose(fp);
                optind++;
            }

    
    exit(EXIT_SUCCESS);
}

/* fileconversion:  convert file ifp to file ofp, direction is up to flag
 * 'u2l' and 'l2u' */
void fileconversion(FILE *ifp, FILE *ofp, int u2l, int l2u)
{
    int i;
    char sbuf[MAXSIZE] = "";
    char dbuf[MAXSIZE] = "";

    while (fgets(sbuf, MAXSIZE, ifp) != NULL) {
        memset(dbuf, 0, MAXSIZE);
        for (i = 0; *(sbuf+i) != '\0'; ++i)
            if (u2l == 1)
                *(dbuf+i) = tolower(*(sbuf+i));
            else if (l2u == 1)
                *(dbuf+i) = toupper(*(sbuf+i));
        fputs(dbuf, ofp);
    }
}
