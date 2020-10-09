#include <stdio.h>

/* count blanks, tabs, and newlines */
int main()
{
    int c, bl, tab, nl;
    
    bl = 0;
    tab = 0;
    nl = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ')
            ++bl;
        else if (c == '	')
            ++tab;
        else if (c == '\n')
            ++nl;
    }
    printf("blanks count is %d\ntabs count is %d\nnewlines count is %d\n", bl, tab, nl);

    return 0;
}
