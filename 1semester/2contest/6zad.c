#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    int i, N, j, k = 3;
    scanf("%d", &N);
    int a[N], b[N], c[N];
    for (i = 0; i <= (N - 1); i++)
    {
        scanf("%d", &a[i]);
    }
    for (i = 0; i <= (N - 1); i++)
    {
        c[i] = a[i];
    }
    while (k > 1)
    {
        for (i = 0; i < N; i++)
        {
            j = c[i] - 1;
            b[i] = a[j];
        }
        k--;
        for (i = 0; i < N; i++)
        {
            a[i] = b[i];
        }
    }
    for (i = 0; i <= (N - 1); i++)
    {
        printf("%d ", b[i]);
    }
    return 0;
}

