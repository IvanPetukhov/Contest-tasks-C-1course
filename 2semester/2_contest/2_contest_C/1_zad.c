#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int x, y, z;
    scanf("%u", &x);
    y = 1;
    z = 0;
    do
    {
        z ^= y;
        y ^= z;
        z ^= y;
        y += z;
        x--;
    } while(x > 0);
    printf("%u\n", z);
    return 0;
}

