#include<stdio.h>
#include<stdlib.h>

long int multiply(void);
long int divide(void);

long int multiply(void)
{
    char c;
    long int a, b;
    if (scanf("%ld", &a) == 0)
    {
        scanf(" %c", &c);
        if (c == '/')
            a = divide();
        if (c == '*')
            a = multiply();
    }
    if (scanf("%ld", &b) == 0)
        {
            scanf(" %c", &c);
            if (c == '/')
                b = divide();
            if (c == '*')
                b = multiply();
        }
return(a * b);
}

long int divide(void)
{
    long int a, b;
    char c;
    if (scanf("%ld", &a) == 0)
    {
        scanf(" %c", &c);
        if (c == '*')
            a = multiply();
        if (c == '/')
            a = divide();
    }
    if (scanf("%ld", &b) == 0)
        {
            scanf(" %c", &c);
            if (c == '/')
                b = divide();
            if (c == '*')
                b = multiply();
        }
    return (a / b);
}

int main(void)
{
    long int x;
    char c;
    if (scanf("%ld", &x) == 0)
    {
        scanf("%c", &c);
        if (c == '*') printf("%ld", multiply());
        else printf("%ld", divide());
    }
    else printf("%ld", x);
    return 0;
}

