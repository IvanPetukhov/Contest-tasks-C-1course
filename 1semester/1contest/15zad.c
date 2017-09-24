#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    int N, x1, y1, x2, y2, x, y, x3, y3, x4, y4, proizv, proizv1, k, i;
    scanf("%d", &N);
    k = 1;
    scanf("%d%d%d%d", &x1, &y1, &x, &y);
    x3 = x1;
    y3 = y1;
    x4 = x;
    y4 = y;
    proizv1 = 0;
    for (i = 2; i < N; i++)
    {
        scanf("%d%d", &x2, &y2);
        proizv = (x1 - x) * (y2 - y) - (y1 - y) * (x2 - x);
        if (proizv1 != 0 && proizv1 * proizv < 0 && k != 0)
        {
            printf("No");
            k = 0;
            break;
        }
        /*printf ("%d %d\n", proizv1*proizv, k);*/
        proizv1 = proizv;
        x1 = x;
        y1 = y;
        x = x2;
        y = y2;
    }
    proizv = (x3 - x4)* (y - y4) - (x - x4) * (y3 - y4);
    if (proizv1 * proizv < 0 && k !=0)
    {
        printf("No");
        k = 0;
    }
    /*printf ("%d %d\n", proizv1*proizv, k);*/
    proizv1 = proizv;
    proizv = (x - x3) * (y4 - y3) - (x4 - x3) * (y - y3);
    if (proizv1 * proizv <= 0 && k != 0)
    {
        printf("No");
        k = 0;
    }
    /*printf ("%d %d\n", proizv1*proizv, k);*/
    if (k != 0)
        printf("Yes");
    return 0;
}
