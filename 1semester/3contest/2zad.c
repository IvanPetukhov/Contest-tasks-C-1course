#include<stdio.h>
#include<stdlib.h>
#include<math.h>

long int isprime (long int a)
{
    long int tr = 0, i;
    if (a == 1)
    {
        tr = 1;
        a++;
    }
    if (a == 2 || a == 3)
    {
        tr = 1;
        a++;
    }
    while (tr == 0)
    {
        for (i = 2; i < ((int)sqrt(a) + 1); i++)
        {
            if (a % i == 0)
            {
                tr = 0;
                break;
            }
            else
                tr = 1;
        }
        a++;
    }
    a--;
    return a;
}

int main(void)
{
    long int n;
    scanf("%ld", &n);
    printf("%ld", isprime(n));
    return 0;
}
