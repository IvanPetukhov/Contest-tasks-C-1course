#include<stdio.h>
#include<stdlib.h>
#define N 8

int main(void)
{
    int i, j, max1 = 0, max2 = 0, sum = 0;
    int a[N], b[N];
    for (i = 0; i < N; i++)
    {
        scanf("%d", &a[i]);
        if (a[i] > max1)
            max1 = a[i];
    }
    for (i = 0; i < N; i++)
    {
        scanf("%d", &b[i]);
        if (b[i] > max2)
            max2 = b[i];
    }
    if (max1 == max2)
    {
        for (i = 0; i < N; i++)
        {
            for (j = 0; j < N; j++)
            {
                if (a[i] == b[j])
                {
                    b[j] = 0;
                    break;
                }
            }
        }
        for (i = 0; i < N; i++)
        {
            sum += a[i] + b[i];
        }
        printf("%d", sum);
    }
    else
        printf("-1");
    return 0;
}

