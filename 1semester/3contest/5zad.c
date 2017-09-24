#include<stdio.h>
#include<stdlib.h>

unsigned long long int turn(long long int a)
{
    unsigned long long int k = 1, ch = 0;
    while (k <= a)
    {
        k = k * 10;
    }
    k /= 10;
    while(a > 0)
    {
        ch = ch + ((a % 10) * k);
        k /= 10;
        a /= 10;
    }
    return ch;
}

int main(void)
{
    long long int n, i;
    unsigned long long int m, p;
    scanf("%llu%lld", &m, &n);
    for (i = 1; i <= n; i++)
    {
        p = turn(m);
        m += p;
    }
    if (m == turn(m)) printf("Yes\n%llu", m);
    else printf("No");
    return 0;
}
