#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int check_period(char *s, long long int t, long long int length)
{
    long long int i;
    for (i = 0; i < (length - t); i++)
    {
        if (s[i] != s[i + t])
            return 0;
    }
    return 1;
}
int main(void)
{
    char s[10001];
    long long int t, length;
    gets(s);
    length = strlen(s);
    for (t = 1; t <= length; t++)
        if (check_period(s, t, length) == 1)
            printf("%lld ", t);
    return 0;
}

