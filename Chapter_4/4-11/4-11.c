#include <stdio.h>

#define max(x, y)            (x) > (y) ? (x) : (y)
#define square(x)            (x) * (x)
#define dprint(expr)         printf(#expr " = %d\n", expr)
#define paste(front, back)   front ## back
#define swap(t, x, y)        {t temp; temp = x; x = y; y = temp;}

//declare functions
int testmax();
int testsquare();
int testsideeffect();
int testdprint();
int testpaste();
int ex4_14();
void printinfo();

int main()
{
    int choose = -1;

    while (choose != 0) {
        // print title
        printinfo();

        scanf("%d", &choose);

        switch(choose) {
            case 1 :
                testmax();
                break;

            case 2 :
                testsquare();
                break;

            case 3 :
                testsideeffect();
                break;

            case 4 :
                testdprint();
                break;

            case 5 :
                testpaste();
                break;

            case 6 :
                ex4_14();
                break;

            default :
                break;
        }
    }
    return 0;
}

int testmax()
{
    int a, b, c;

    a = 7;
    b = 10;

    c = max(a, b);

    printf("c = %d\n", c);

    return 0;

}

int testsquare()
{
    int z = 4;
    printf("square(z+1) = %d\n", square(z+1));

    return 0;
}

int testsideeffect()
{
    int i, j;

    i = 2;
    j = 3;

    printf("i = %d\tj = %d\n", i, j);
    printf("max(i, j) = %d\n", max(i++, j++));
    printf("i = %d\tj = %d\n", i, j);
    printf("square(i) = %d\tsquare(j) = %d\n", square(i++), square(j++));
    printf("i = %d\tj = %d\n", i, j);

    return 0;
}

int testdprint()
{
    int x, y;

    x = 7;
    y = 1;

    dprint(x);
    dprint(y);
    dprint(x+y);
    dprint(x-y);
    dprint(x*y);
    dprint(x/y);

    return 0;
}

int testpaste()
{
    char yueyun, wen;
    char paste(yueyun, wen) = '3';

    printf("%x\n", paste(yueyun, wen));

    return 0;
}
int ex4_14()
{
    int x, y;

    x = 99;
    y = 88;

    printf("t = int, x = %d, y = %d\n", x, y);
    swap(int, x, y)
    printf("after swap, x = %d, y = %d\n", x, y);

    return 0;
}
void printinfo()
{
    printf("Input 1 testmax\n");
    printf("      2 testsquare\n");
    printf("      3 test side effect\n");
    printf("      4 test dprint\n");
    printf("      5 test paste\n");
    printf("      6 test ex4_14\n");
    printf("      0 exit\n");
    printf("Input: ");
}
