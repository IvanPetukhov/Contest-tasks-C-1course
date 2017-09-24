#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    long long int N, i;
    scanf("%lld", &N);
    unsigned a[N], x, x1, x2;
    scanf("%u", &a[0]);
    x = a[0];
    x1 = 0;
    x2 = 0;
    for (i = 1; i < N; i++)
    {
        scanf("%u", &a[i]);
        x ^= a[i];
    }
    for (i = 0; i < N; i++)
    {
        if ((x ^ a[i]) < a[i])
        {
            x1 ^= x ^ a[i];
            x2 ^= a[i];
        }
    }
    printf("%u %u", x1, x2);
    return 0;
}

