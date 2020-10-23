#include <stdio.h>
#include <ctype.h>

#define SIZE  10
int getch(void);
void ungetch(int);
int getint(int *);

int main() 
{
    /* int *pn;
    int c;
    while ((c = getint(pn)) != EOF)
        printf("%d ", *pn); */
    int n, array[SIZE];
    for (n = 0; n < SIZE && getint(&array[n]) != EOF; n++)
        printf("%d ", array[n]);
<<<<<<< Updated upstream
    /* test git stash */
=======
    /* for (n = 0; n < SIZE; n++)
        printf("%d ", array[n]);*/
>>>>>>> Stashed changes
    printf("\n");

    return 0;
}


/* getint: get next integer from input into *pn */ 
int getint(int *pn)
{
    int c, sign;

    while (isspace(c = getch()))	/* skip white space */
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);	/* it's not a number */
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
        c = getch();
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
    *pn *= sign;
    if (c != EOF)
        ungetch(c);

    return c;
}
