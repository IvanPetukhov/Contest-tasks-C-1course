#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    int N, M, i, j, pol, k, X, A;
    scanf("%d", &N);
    int a[N];
    for (i = 0; i < N; i++)
    {
        scanf("%d", &a[i]);
    }
    scanf("%d", &M);
    int x[M];
    for (i = 0; i < M; i++)
    {
        scanf("%d", &x[i]);
    }
    for (i = (M - 1); i >= 0; i--)
    {
        X = 1;
        pol = 0;
        for (j = 0; j < N; j++)
        {
            X = 1;
            A = a[j];
            k = j;
            while (k > 0)
            {
                X *= x[i];
                k--;
            }
            pol += A * X;
        }
        printf("%d ", pol);
    }
    return 0;
}

