#include<stdio.h>
#include<stdlib.h>
#include<string.h>

unsigned int maximum (unsigned int a, unsigned int b, unsigned int c)
{
    if (a >= b)
        if (a >= c)
            return a;
    if (b >= a)
        if (b >= c)
            return b;
    if (c >= b)
        if (c >= a)
            return c;
    return 0;
}

int main (void)
{
    int m, n;
    scanf("%d%d", &n, &m);
    int i, j;
    unsigned int **a = (unsigned int **) malloc (n * sizeof(unsigned int *));
    unsigned int money = 0;
    for (i = 0; i < n; i++)
    {
        a[i] = (unsigned int *) malloc (m * sizeof(unsigned int));
        for (j = 0; j < m; j++)
            scanf("%u", &a[i][j]);
    }
    for (j = 1; j < m; j++)
    {
        for (i = 0; i < n; i++)
        {
            if ((i != 0) && (i != n - 1))
            {
                a[i][j] += maximum(a[i - 1][j - 1], a[i][j - 1], a[i + 1][j - 1]);
            }
            else
                if (i == 0)
                    a[i][j] += maximum(0, a[i][j - 1], a[i + 1][j - 1]);
                else
                    a[i][j] += maximum(a[i - 1][j - 1], a[i][j - 1], 0);
        }
    }
    for (i = 0; i < n; i++)
        if (a[i][m - 1] > money)
            money = a[i][m - 1];
    printf("%u", money);
    for (i = 0; i < n; i++)
        free(a[i]);
    free(a);
    return 0;
}
