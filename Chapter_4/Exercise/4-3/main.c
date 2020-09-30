#include <stdio.h>
#include <stdlib.h>
#include "calc.h"

#define MAXOP 100

/* reverse Polish calculator */
int main()
{
    int type;
    double op2;
    int op3, op4;	/* for modulus operation */
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor\n");
            case '%':
                if (op3 = pop() != 0.0) {
                if (!Isinteger(op3) && !Isinteger(op4 = pop())) {
                    push(op4 % op3);
                }
                else
                    printf("error: modulus include decimal point\n");
                 }
                else
                    printf("error: zero divisor\n");
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    return 0;
}
