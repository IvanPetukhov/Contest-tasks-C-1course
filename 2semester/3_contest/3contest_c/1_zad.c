#include <stdio.h>
#include <stdlib.h>

unsigned int f(unsigned int x)
{
    if (x == 0)
        return 1;
    else
    {
        x--;
        x = f(x);
    }
    return 3*x;
}

int main(void)
{
    unsigned int x;
    scanf("%u", &x);
    printf("%u\n", f(x));
    return 0;
}

