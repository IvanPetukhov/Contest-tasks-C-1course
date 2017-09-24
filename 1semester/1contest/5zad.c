#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    long long sum, c, b, a, i;
    i = 2;
    scanf("%lld", &a);
    sum = a;
    scanf("%lld", &a);
    b = a;
    c = 0;
    while (a != 0)
    {
        scanf("%lld", &a);
        if (i%2 == 0 && a == 0) sum = sum + c;
        if (a == 0 && i == 2)
        {
            sum = sum + b;
            break;
        }
        if (a == 0) break;
        if (i % 2 == 0) b = b * a;
        if (i % 2 != 0)
        {
            b = 0;
            c = a;
        }
        i++;
        sum = sum + b;
        b = a;
    }
    printf("%lld", sum);
    return 0;
}

