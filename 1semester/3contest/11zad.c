#include<stdio.h>
#include<stdlib.h>

int NOD (int a, int b)
{
    if (b == 0)
        return a;
    return (NOD(b, a % b));
}

int calc(int * a, int * b, int N, int i)
{
    int c, d;
    scanf("%d%d", &c, &d);
    *a = (*a) * d + c * (*b);
    *b = (*b) * d;
    i++;
    if (i < N) calc(a, b, N, i);
    return 0;
}

int main(void)
{
    int N, a, b, x, y, z, k, i = 1;
    scanf("%d", &N);
    scanf("%d%d", &a, &b);
    if (N > 1)
    {
        calc(&a, &b, N, i);
    }
    x = a / b;
    k = NOD((a - (x * b)), b);
    y = (a - (x * b)) / k;
    z = b / k;
    printf("%d %d %d", x, y, z);
    return 0;
}

