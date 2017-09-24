#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int isprime(int a)
{
    int i;
    for (i = 2; i < ((int)sqrt(a) + 1); i++)
    {
        if (a % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

void build (int a, int k, int N)
{
    int b, i;
    if (k == N)
    {
        printf("%d ", a);
        return;
    }
    for (i = 1; i < 10; i += 2)
    {
        b = 10 * a + i;
        if (isprime(b) == 1)
        {
            k++;
            build(b, k, N);
            k--;
        }
    }
}

int main (void)
{
    int N;
    scanf("%d", &N);
    build(2, 1, N);
    build(3, 1, N);
    build(5, 1, N);
    build(7, 1, N);
    return 0;
}

