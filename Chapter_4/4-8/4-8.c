#include <stdio.h>

#define dprint(var)   printf(#var " = %d\n", var)

int i = 100;

int main()
{
    int i;  // outer declaration i

    i = 99;
    dprint(i);  // print outer i

    if (i > 98) {
        int i = 97;

        // print inside i
        printf("inside if block, i = %d\n", i);
    }

    dprint(i);  // printf outer i again

    return 0;
}
