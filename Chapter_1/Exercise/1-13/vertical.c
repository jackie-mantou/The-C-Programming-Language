#include <stdio.h>

#define MAX 100
/* Write a program to print a histogram of the lengths of words in its 
 * input. Vertical version */
int getmax(int length[], int *gmax[]);
int main()
{
    int length[MAX] = {0};
    int c, i, j, k, l;
    int gmax[2] = {0};
    j = 0;
    char symbol = '|';

    while ((c = getchar()) != EOF) {
        putchar(c);
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            i = 1;
            while (((c = getchar()) >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
                ++i;
            }
            length[j++] = i;
        }
    }
    putchar('\n');

    if (getmax(length, &gmax)) {
        printf("get max failed!\n");
        return -1;
    }
    k = gmax[1];
    l = j - k;
    while (gmax[0]-- > 0) {
        while (k-- >= 0)
            printf("\t");
        printf("%c", symbol);
        while (l-- > 0)
            printf("\t");
        printf("\n");
    }

    return 0;
}

int getmax(int length[], int *gmax[])
{
    /* statements of verify whether the array length is legal  */
    int i = 0;

    while (length[i] != 0) {
        if (*gmax[0] <= length[i]) {
            *gmax[0] = length[i];
            *gmax[1] = i;
        }
        ++i;
    }

    return 0;
}
