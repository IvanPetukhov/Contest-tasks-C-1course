#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    int a[99999], b[99999], i = 0, j = 0, k1 = 1, k2 = 1;
    while(k1 != 0 && k2 != 0)
    {
        scanf("%d", &k1);
        if (k1 != 0)
        {
            a[i] = k1;
            i ++;
        }
        if (k1 != 0)
        {
            scanf("%d", &k2);
            if (k2 != 0)
            {
                b[j] = k2;
                j++;
            }
        }
    }
    i = 0;
    while (a[i] != 0)
    {
        printf("%d ", a[i]);
        i++;
    }
    j--;
    while (j >= 0)
    {
        printf("%d ", b[j]);
        j--;
    }
    return 0;
}

