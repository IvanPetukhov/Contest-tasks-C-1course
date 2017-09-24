#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int N;
    char c;
    scanf("%d", &N);
    while (c != '.')        /*65-90, 97-122*/
    {
        scanf("%c", &c);
        if (c == ' ' || c == '.') printf("%c", c);
        else if (c >= 'A' && c <= 'Z') printf("%c", (c - 'A' + N) % 26 + 'A');
            else printf("%c", (c - 'a' + N) % 26 + 'a');
    }
    return 0;

}

