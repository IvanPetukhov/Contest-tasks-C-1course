#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void turn(char * s, int L)
{
    char c;
    int i;
    for (i = 0; i < L/2; i++)
    {
        c = s[i];
        s[i] = s[L - i - 1];
        s[L - i - 1] = c;
    }
}

int main (void)
{
    int L;
    scanf("%d", &L);
    char *s = (char *) malloc (L * sizeof(char));
    char *s1 = (char *) malloc (L * sizeof(char));
    scanf("\n");
    fgets(s, L + 1, stdin);
    turn(s, L);
    strcpy(s1, s);
    turn (s, L);
    if (!strcmp(s,s1))
        printf("YES");
    else
        printf("NO");
    return 0;
}

