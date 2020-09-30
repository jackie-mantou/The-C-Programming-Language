#include <stdio.h>
#include <ctype.h>
#include "calc.h"
#define MAX   100

/* getop: get next operator or numeric operand */
int getop(char s[])
{
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.')
        return c;        /* not a number */
    i = 0;
    if (isdigit(c))        /* collect integer part */
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.')        /* collect fraction part */
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);

    return NUMBER;
}

/* verify the number whether include a decimal point */
int Isinteger(double d)
{
    int i;
    char s[MAX];
    sprintf(s, "%f", d);
    for (i = 0; s[i] != '.' && s[i] != '\0'; i++)
        ;
    if (s[i] = '\0')
        return 0;
    else 
        return -1;
}
