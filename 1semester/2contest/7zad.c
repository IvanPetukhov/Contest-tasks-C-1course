#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    int i, N, j, tr = 0;
    scanf("%d", &N);
    int a[N], b[N];
    for (i = 0; i < N; i++)
    {
        scanf("%d", &a[i]);
    }
    for (i = 0; i < N; i++)
    {
        b[i] = i+1;
        for (j = 0; j < N; j++)
        {
            if (b[i] == a[j])
            {
                a[j] = 0;
                break;
            }
        }
    }
    for (i = 0; i< N; i++)
    {
        if (a[i] != 0) tr = 1;
    }
    if (tr == 0)
        printf("Yes");
    else
        printf("No");
    return 0;
}

