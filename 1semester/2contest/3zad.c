#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    int i, N, M, tr = 0;
    scanf("%d", &N);
    int a[N];
    if (N != 0)
    {
        for (i = 0; i <= (N - 1); i++)
        {
            scanf("%d", &a[i]);
        }
    }
    scanf("%d", &M);
    int b[M];
    if (M != 0)
    {
        for (i = 0; i <= (M - 1); i++)
        {
            scanf("%d", &b[i]);
        }
    }
    if (M == N)
    {
        for (i = 0; i <= (N - 1); i++)
        {
            printf("%d %d ", a[i], b[i]);
        }
    }
    if (M == 0)
    {
        for (i = 0; i <= (N - 1); i++)
        {
            printf("%d ", a[i]);
            tr = 1;
        }
    }
    if (N == 0)
    {
        for (i = 0; i <= (M - 1); i++)
        {
            printf("%d ", b[i]);
            tr = 1;
        }
    }
    if (M < N && tr !=1)
    {
        for (i = 0; i <= (M - 1); i++)
        {
            printf("%d %d ", a[i], b[i]);
        }
        for (i = M; i <= (N - 1); i++)
        {
            printf("%d ", a[i]);
        }
    }
    if (M > N && tr != 1)
    {
        for (i = 0; i <= (N - 1); i++)
        {
            printf("%d %d ", a[i], b[i]);
        }
        for (i = N; i <= (M - 1); i++)
        {
            printf("%d ", b[i]);
        }
    }
    return 0;
}

