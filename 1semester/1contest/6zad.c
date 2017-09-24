#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    unsigned N;
    int K;
    scanf("%u%d", &N, &K);
    N = (N >> K) + (N << (32 - K));
    printf("%u", N);
    return 0;
}

