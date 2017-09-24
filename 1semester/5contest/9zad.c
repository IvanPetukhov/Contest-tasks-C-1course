#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int raz (int a, int b)
{
    if (a >= b)
        return (a - b);
    else
        return (b - a);
}

int main (void)
{
    int m, n;
    scanf("%d%d", &n, &m);
    int k, i, j, h;
    int time = 0, p = 1000000;
    scanf("%d", &k);
    int *y = (int *) malloc (k * sizeof (int));
    int *x = (int *) malloc (k * sizeof (int));
    for (i = 0; i < k; i++)
        scanf("%d%d", &x[i], &y[i]);
    int **a = (int **) malloc (n * sizeof (int));
    for (i = 0; i < n; i++)
    {
        a[i] = (int *) malloc (m * sizeof (int));
    }
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
        {
            p = 1000000;
            for (h = 0; h < k; h++)
            {
                if ((raz(i, y[h] - 1) + raz(j, x[h] - 1))< p)
                {
                    p = raz(i, y[h] - 1) + raz(j, x[h] - 1);
                }
                a[y[h] - 1][x[h] - 1] = 0;
            }
            a[i][j] = p;
        }
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
        {
            if (a[i][j] > time)
                time = a[i][j];
        }
    printf("%d", time);
    for (i = 0; i < n; i++)
        free(a[i]);
    free(a);
    free(x);
    free(y);
    return 0;
}
