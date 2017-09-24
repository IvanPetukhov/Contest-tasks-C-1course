#include<stdio.h>
#include<stdlib.h>

void shellsort(int l[], int n, int r[])
{
int j, i, mid, L, R;
for(mid = n / 2; mid > 0; mid /= 2)
{
    for(j = mid; j < n; j++)
    {
        for( i = j - mid; i >= 0; i -= mid)
        {
            if(l[i + mid] >= l[i])
            break;
            else
            {
                L = l[i];
                l[i] = l[i + mid];
                l[i + mid] = L;
                R = r[i];
                r[i] = r[i + mid];
                r[i + mid] = R;

            }
        }
    }
}
}

int h(int l[], int r[], int n)
{
    int i;
    int R = r[0], L = l[0];
    if (n == 1)
    {
        printf("%d %d", l[0], r[0]);
        return 0;
    }
    if (n == 2)
    {
        if (l[1] == l[0])
        {
            if (r[0] >= r[1])
                printf("%d %d", l[0], r[0]);
            else
                printf("%d %d", l[1], r[1]);
        }
        else
        {
            if (l[1] <= r[0])
            {
                if (r[1] > r[0])
                    printf("%d %d", l[0], r[1]);
                else
                    printf("%d %d", l[0], r[0]);
            }
            else
            {
                printf("%d %d %d %d", l[0], r[0], l[1], r[1]);
            }
        }
        return 0;
    }
    for (i = 1; i < n; i++)
    {
        if (l[i] > R)
        {
            printf("%d %d ", L, R);
            L = l[i];
            R = r[i];
        }
        if (l[i] < R)
        {
            if (r[i] > R)
                R = r[i];
        }
        if(l[i] == R)
        {
           R = r[i];
        }

    }
    printf("%d %d ", L, R);
    return 0;
}

int main(void)
{
    int N, i;
    scanf("%d", &N);
    int l[N], r[N];
    for(i = 0; i < N; i++)
    {
        scanf("%d %d", &l[i], &r[i]);
    }
    shellsort(l, N, r);
    h(l, r, N);
    return 0;
}

