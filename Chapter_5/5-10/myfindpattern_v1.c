#include <stdio.h>
#include <string.h>
#define MAXSIZE   1000

/* find pattern from standard input, version 1 */

int mygetline(char line[], int lim);

int main(int argc, char *argv[])
{
    /* 1 get a line from stand input 
     * 2 find pattern (strstr) */
    char line[MAXSIZE] = "";
    int found;

    found = 0;

    while (mygetline(line, MAXSIZE) > 0) {
        if (strstr(line, argv[1]) != NULL) {
            printf("Find pattern in line: %s", line);
            found++;
        }
    }

    return found;
}

/* get a line from standard input, return length */
int mygetline(char line[], int lim)
{
    int i, c;

    i = 0;

    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        line[i++] = c;

    if (c == '\n')
        line[i++] = c;

    line[i] = '\0';

    return i;
}
