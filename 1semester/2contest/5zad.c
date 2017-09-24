#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    int i, N, j, tr = 0;
    scanf("%d", &N);
    float x[N], y[N], z[N], r[N];
    for (i = 0; i <= (N - 1); i++)
    {
        scanf("%f %f %f %f", &x[i], &y[i], &z[i], &r[i]);
    }
    for (i = 0; i <= (N - 2); i++)
    {
        if (tr == 1)
            break;
        for (j = (i + 1); j <= (N - 1); j++)
        {
            if ((x[j] - x[i]) * (x[j] - x[i]) + (y[j] - y[i]) * (y[j] - y[i]) +
                (z[j] - z[i]) * (z[j] - z[i]) <= (r[j] + r[i]) * (r[j] + r[i]))
            {
                tr = 1;
                break;
            }
        }
    }
    if (tr == 1)
        printf("YES");
    else
        printf("NO");
    return 0;
}
