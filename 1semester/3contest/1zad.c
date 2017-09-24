#include <stdio.h>
#include <stdlib.h>

int NOD (int k, int l)
{
    while (l != 0)
    {
        int r = k % l;
        k = l;
        l = r;
    }
    return k;
}
int main(void)
{
    int a, b, c, d, n;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    n = NOD (a, b);
    n = NOD (n, c);
    n = NOD (n, d);
    printf("%d", n);
    return 0;
}

