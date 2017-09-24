#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(void)
{
    int N, i;
    scanf("%d", &N);
    float s[N], a[N], v0 = 0, v1, t = 0;
    for (i = 0; i < N; i++)
    {
        scanf("%f", &s[i]);
    }
    for (i = 0; i < N; i++)
    {
        scanf("%f", &a[i]);
    }
    for (i = 0; i < N; i++)
    {
        if ((a[i] > 0) || (a[i] < 0))
        {
            v1 = sqrt((2 * a[i] * s[i]) + (v0 * v0));
            t += (v1 - v0) / a[i];
            v0 = v1;
        }
        else
        {
            t += s[i] / v0;
        }
    }
    printf("%.4f", t);
    return 0;
}
