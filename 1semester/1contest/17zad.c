#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int N, i;
    unsigned a, mask;
    scanf("%d", &N);
    scanf("%u", &a);
    mask = a;
    for (i = 1; i < N; i++)
    {
        scanf("%u", &a);
        mask = mask ^ a;
    }
    printf("%d\n", mask);
    return 0;
}

