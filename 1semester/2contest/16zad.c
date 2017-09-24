#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    int a[99999], b[99999], i, N, j, MAXimum = 0, MAximum = 0, Maximum = 0;
    scanf("%d", &N);
    for (i = 0; i <= (N - 1); i++)
    {
        b[i] = 0;
    }
    for (i = 0; i <= (N - 1); i++)
    {
        scanf("%d", &a[i]);
    }
    for (i = 0; i <= (N - 2); i++)
    {
        for (j = i+1; j <= (N - 1); j++)
        {
            if (a[i] == a[j] && a[i] != 0)
            {
                b[i]++;
                b[j]++;
                a[j] = 0;
                a[i] = 0;
            }
        }
    }
    for (i = 0; i <= (N - 1); i++)
    {
        if (b[i] != 0) a[i] = 0;
    }
    for (i = 0; i <= (N - 1); i++)
    {
        if (a[i] > MAXimum) MAXimum = a[i];
        if (a[i] < MAXimum && a[i] > MAximum) MAximum = a[i];
        if (a[i] < MAximum && a[i] > Maximum) Maximum = a[i];
    }
    for (i = 0; i <= (N - 1); i++)
    {
        if (a[i] < MAXimum && a[i] > MAximum) MAximum = a[i];
    }
    for (i = 0; i <= (N - 1); i++)
    {
        if (a[i] < MAximum && a[i] > Maximum) Maximum = a[i];
    }
    printf("%d %d %d", Maximum, MAximum, MAXimum);
    return 0;
}

