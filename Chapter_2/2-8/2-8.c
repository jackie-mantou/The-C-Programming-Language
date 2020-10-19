#include <stdio.h>

/* learn the difference between '++n' and 'n++' */
int main()
{
    int x, y, n = 5;
    x = y = 0;

    //x = ++n;
    //y = n++;
    //printf("n = %d\n++n = %d  n++ = %d\n", n, x, y);
    printf("n = %d\n++n = %d  n++ = %d\n", n, ++n, n++);
    /* printf("n = %d\n", n);
    printf("++n = %d\n", ++n);
    printf("n++ = %d\n", n++); */


    return 0;
}
