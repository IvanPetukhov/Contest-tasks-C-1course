#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void moving_word(char * s, long long int l)
{
    int i;
    char a = s[0];
    for (i = 0; i < l - 1; i++)
    {
        s[i] = s[i + 1];
    }
    s[l - 1] = a;
}

int main(void)
{
    char s[83];
    long long int N;
    long long int length, i, movement;
    scanf("%lld", &N);
    scanf("\n");
    gets(s);
    length = strlen(s);
    movement = N % length;
    for (i = 0; i < movement; i++)
    {
        moving_word(s, length);
    }
    puts(s);
    return 0;
}

