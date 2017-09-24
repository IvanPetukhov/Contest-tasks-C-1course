#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Petukhov Ivan
// Group 102
// Task #10 contest #4
void prefix_f(char * s, int * pi, int l)
{
    int j, i;
    for(j = 1; j < l; j++)
    {
        i = pi[j - 1];
        while ((i > 0) && (s[j] != s[i]))
            i = pi[i - 1];
        if (s[j] == s[i])
            i++;
        pi[j] = i;
    }
    return;
}

int main(void)
{
    char s[1000003], s1[1000003], *s2;
    int *pi;
    int l , l1, k;
    gets(s);
    gets(s1);
    l = strlen(s);
    l1 = strlen(s1);
    k = l1 + l + 1;
    s2 = (char *)calloc(k + 1, sizeof(char));
    pi = (int *)calloc(k + 1, sizeof(int));
    strcat(s2, s);
    strcat(s2, " ");
    strcat(s2, s1);
    prefix_f(s2, pi, l + l1 + 1);
    printf("%d ", pi[l + l1]);
    free(pi);
    free(s2);
    s2 = (char *)calloc(k + 1, sizeof(char));
    strcat(s2, s1);
    strcat(s2, " ");
    strcat(s2, s);
    pi = (int *)calloc(k + 1, sizeof(int));
    prefix_f(s2, pi, l + l1 + 1);
    printf("%d", pi[l + l1]);
    free(s2);
    free(pi);
    return 0;
}


