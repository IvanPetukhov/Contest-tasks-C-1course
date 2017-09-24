#include<stdio.h>
#include<stdlib.h>

int sequence(int a[], int pos, int min_znach, int k, int n)
{
    int i = 0;
    if ((min_znach >= n) && (pos != k))
        return 0;
    if (pos == k)
    {
        for(i = 0; i < k; i++)
        {
            printf("%d ", a[i]);
        }
        printf("\n");
        return 0;
    }
    for(i = min_znach; i < n; i++)
    {
        a[pos] = i;
        sequence(a, pos + 1, i + 1, k, n);
    }
    return 0;
}

int main(void)
{
    int n, k, i;
    scanf("%d%d", &n, &k);
    int a[n];
    for (i = 0; i < k; i++)
    {
        a[i] = i;
    }
    sequence(a, 0, 0, k, n);
    return 0;
}

