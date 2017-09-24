#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    int i, N, j, k, kol = 0;
    scanf("%d", &N);
    int a[N - 1];
    for (i = 0; i < N; i++)
    {
        scanf("%d", &a[i]);
    }
    for (i = 1; i < (N - 1); i++)
    {
        for (j = i + 2; j < (N + 1); j++)
            {
                if ((i != (i + j) / 2) && ((i + j) % 2 == 0))
                {
                    k = (i + j) / 2;
                    if((a[k - 1] == (a[i - 1] + a[j - 1]) / 2) && ((a[i - 1] + a[j - 1]) % 2 == 0))
                    {
                        if ((1 <= i) && (i < k) && (k < j) && (j <= N)) kol++;
                    }
                }
            }

    }
    printf("%d", kol);
    return 0;
}


