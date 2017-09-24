#include <stdio.h>
#include <stdlib.h>


int main(void)
{
    double X, a, sin;
    int N, i, m, k, stepen;
    scanf("%lf%d", &X, &N);
    i = 1;
    stepen = 1;
    m = 1;
    sin = 0;
    while (i <= N)   /*sin(x) = x - x^3/3! + x^5/5! - x^7/7! + ...*/
    {
        a = 1;
        k = 1;
        while (k <= m)
        {
            a = a*X/k;
            k++;
        }
        sin = sin + a*stepen;
        stepen = stepen * (-1);
        m = m + 2;
        i++;
    }
    printf("%.6lf\n", sin);
    return 0;
}

