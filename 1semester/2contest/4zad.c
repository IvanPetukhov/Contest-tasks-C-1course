#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    int i, N, vid;
    scanf("%d", &N);
    int a[N], b[N];
    vid = 0;
    for (i = 0; i <= (N - 1); i++)
    {
        scanf("%d", &a[i]);
    }
    for (i = 0; i <= (N - 1); i++)
    {
        scanf("%d", &b[i]);
        if (a[i] >= b[i])
            vid += a[i];
        else
            vid += b[i];
    }
    printf("%d", vid);
    return 0;
}

