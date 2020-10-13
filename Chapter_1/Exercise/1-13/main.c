#include <stdio.h>

/* print a histogram of the lengths of words in its input */
int main()
{
    int c, i;

    while ((c = getchar()) != EOF) 
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            putchar(c);
            i = 1;
            while (((c = getchar ()) >= 'a' && c <= 'z') || 
                    (c >= 'A' && c <= 'Z')) {
                putchar(c);
                ++i;
            }
            putchar('\n');
        }
    
    return 0;
}
