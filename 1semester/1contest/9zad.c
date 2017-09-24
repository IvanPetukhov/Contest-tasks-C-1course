
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    unsigned x;
    int a, b, c, d;
    x = 0;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    x = x + a;
    x <<= 8;
    x = x + b;
    x <<= 8;
    x = x + c;
    x <<= 8;
    x = x + d;
    printf("%u", x);
    return 0;
}
