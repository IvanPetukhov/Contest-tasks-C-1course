#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void)
{
    char * s;
    s = (char *)malloc(sizeof(char) * 1000000);
    long long int k, i, length, j = 0, n, L, letters, sum_space;
    int * l;
    l = (int *)malloc(sizeof(int) * 1000000);
    scanf("%lld", &k);
    scanf("\n");
    gets(s);
    length = strlen(s);
    for(i = 0; i < length; i++)
    {
        if (s[i] == ' ')
            j++;
    }
    n = j;
    letters = length - n;
    sum_space = k - letters;
    L = sum_space / n;
    i = 0;
    while(sum_space > 0)
    {
        while (s[i]!= ' ')
        {
            printf("%c", s[i]);
            i++;
        }
        if (L * n != sum_space)
        {
            for(j = 0; j < L + 1; j++)
                printf(" ");
            sum_space -= (L + 1);
            n--;
        }
        else
        {
            for(j = 0; j < L; j++)
                printf(" ");
            sum_space -= L;
            n--;
        }
        i++;
    }
    for (;i < length; i++)
        printf("%c", s[i]);
    free(l);
    free(s);
    return 0;
}

