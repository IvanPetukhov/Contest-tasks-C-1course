#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int K;
    unsigned N;
    scanf("%u%d", &N, &K);
    N = (N << (32 - K)) >> (32 - K);
    printf("%u", N);
    return 0;
}

