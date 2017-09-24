#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    int a[99999], i = 0, k = 1;
    while(k != 0)
    {
        scanf("%d", &k);
        if (k != 0)
        {
            a[i] = k;
            i++;
        }
    }
    i--;
    while(i >= 0)
    {
        printf("%d ", a[i]);
        i--;
    }
    return 0;
}
