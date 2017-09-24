#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int mask[5] = {0xffff, 0xff00ff, 0xf0f0f0f, 0x33333333, 0x55555555};
    unsigned int a, c, d;
    int * b;
    scanf("%u", &a);
    c = 1;
    b = mask;
    b += 4;
    do
    {
        d = a;
        a &= *b;
        d &= ~(*b);
        a <<= c;
        d >>= c;
        a |= d;
        c *= 2;
        b -= 1;
    } while(b != mask - 1);
    printf("%u\n", a);
    return 0;
}

