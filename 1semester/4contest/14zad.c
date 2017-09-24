#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Petukhov Ivan
// Group 102
// Task #14 contest #4

int main(void)
{
    char s[1000005];
    int i, length;
    int *cht, *necht;
    gets(s);
    length = strlen(s);
    cht = (int *)calloc(length, sizeof(int));
    necht = (int *)calloc(length, sizeof(int));
    for (i = 0; i < length - 1; i++)
    {
        if ((i % 2 == 0) && (s[i] == 'A'))
        {
            necht[length - 1]++;
        }
        if ((i % 2 != 0) && (s[i] == 'A'))
        {
            cht[length - 1]++;
        }
    }
    for (i = length - 2; i >= 0; i--)
    {
        if (i % 2 == 0)
        {
            if (s[i] == 'A')
            {
                if (s[i + 1] != 'A')
                {
                    necht[i]--;
                }
            }
            else
            {
                if (s[i + 1] == 'A')
                {
                    necht[i]++;
                }
            }
        }
        else
        {
            if (s[i] == 'A')
            {
                if (s[i + 1] != 'A')
                {
                    cht[i]--;
                }
            }
            else
            {
                if (s[i + 1] == 'A')
                {
                    cht[i]++;
                }
            }
        }
    }
    for (i = 0; i < length; i++)
        if (cht[i] == necht[i])
            printf("%d ", i + 1);
    free(cht);
    free(necht);
    return 0;
}

