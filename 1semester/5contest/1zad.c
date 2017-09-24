#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void)
{
    long long int N;
    scanf("%lld", &N);
    long long int i, j;
    long long int **x;
    x = (long long int **) calloc (N, sizeof(long long int*));
    long long int **z;
    z = (long long int **) calloc (N, sizeof(long long int*));
    for (i = 0; i < N; i++)
    {
    x[i] = (long long int *) calloc (N, sizeof(long long int));
    z[i] = (long long int *) calloc (N, sizeof(long long int));
    }
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            scanf("%lld%lld", &x[j][i], &z[j][i]);
        }
    }
    for (j = 0; j < N; j++)
    {
        for(i = 0; i < N; i++)
        {
            printf("%lld %lld ", x[j][i], -z[j][i]);
        }
        printf("\n");
    }
    for (i = 0; i < N; i++)
    {
    free(x[i]);
    free(z[i]);
    }
    free(x);
    free(z);
    return 0;
}
