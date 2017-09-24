#include<stdio.h>
#include<stdlib.h>
#define N 8

int main(void)
{
    int i, j, sum = 0, trline, trstr, tr = 1;
    int a[N], b[N], c[N][N];
    for (i = 0; i < N; i++)
    {
        scanf("%d", &a[i]);
    }
    for (i = 0; i < N; i++)
    {
        scanf("%d", &b[i]);
    }
    for (i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
        {
            if (a[i] < b[j])
                c[i][j] = a[i];
            else
                c[i][j] = b[j];
            sum += c[i][j];
        }
    }
    for (i = 0; i < N; i++)
    {
        trline = 0;
        for (j = 0; j < N; j++)
        {
            if (a[i] > b[j])
                trline++;
        }
        if (trline == N)
            tr = 0;
    }
    for (i = 0; i < N; i++)
    {
        trstr = 0;
        for (j = 0; j < N; j++)
        {
            if (a[j] < b[i])
                trstr++;
        }
        if (trstr == N)
            tr = 0;
    }
    if (tr == 0)
        printf("-1");
    else
        printf("%d", sum);
    return 0;
}


