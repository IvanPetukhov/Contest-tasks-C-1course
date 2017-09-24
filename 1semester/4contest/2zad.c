#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void counting_system(char *s, int a)
{
    int h, c = 0;
    for (h = 0; h <= strlen(s); h++)
        {
            if ((s[h] - 'a' == 0) || (s[h] - 'A' == 0) || (s[h] - 'e' == 0) ||
                (s[h] - 'E' == 0) || (s[h] - 'i' == 0) || (s[h] - 'I' == 0) ||
                (s[h] - 'o' == 0) || (s[h] - 'O' == 0) || (s[h] - 'u' == 0) ||
                (s[h] - 'U' == 0) || (s[h] - 'y' == 0) || (s[h] - 'Y' == 0))
            {
                if ((s[h + 1] - 'a' != 0) && (s[h + 1] - 'A' != 0) && (s[h + 1] - 'e' != 0) &&
                    (s[h + 1] - 'E' != 0) && (s[h + 1] - 'i' != 0) && (s[h + 1] - 'I' != 0) &&
                    (s[h + 1] - 'o' != 0) && (s[h + 1] - 'O' != 0) && (s[h + 1] - 'u' != 0) &&
                    (s[h + 1] - 'U' != 0) && (s[h + 1] - 'y' != 0) && (s[h + 1] - 'Y' != 0))
                {
                    c++;
                }
            }
            if ((a == c) && (h == strlen(s)))
            {
                c = 0;
                printf("%s\n", s);
                continue;
            }
            else
                if (h == strlen(s))
                {
                    c = 0;
                    continue;
                }
        }
        return;
}
int main(void)
{
    char s[101];
    long long int N, i;
    int *a;
    a = (int *)malloc(sizeof(int) * 10000);
    scanf("%lld", &N);
    for (i = 0; i <= N; i++)
    {
        scanf("%d", &a[i]);
    }
    for (i = 0; i < N; i++)
    {
        gets(s);
        counting_system(s, a[i]);
    }
    free(a);
    return 0;
}
