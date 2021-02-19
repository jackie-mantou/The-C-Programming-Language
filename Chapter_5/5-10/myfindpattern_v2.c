#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* find pattern from standard input, version 2 */

int main(int argc, char *argv[])
{
    /* 1 get a line from stand input 
     * 2 find pattern (strstr) */
    char *line;
    size_t lsize;
    int found;

    line = NULL;
    lsize = 0;
    found = 0;

    /* ssize_t getline(char **lineptr, size_t *n, FILE *stream) */
    while (getline(&line, &lsize, stdin) > 0) {
        if (strstr(line, argv[1]) != NULL) {
            printf("Find pattern in line: %s", line);
            found++;
        }
    }

    free(line);

    return found;
}
