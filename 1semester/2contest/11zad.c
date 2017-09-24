#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    char ch = '1';
    int n = 0, i, fr = 0, h, l, j;
    int c[64], a[64], d[8][8];
    scanf("%c%d", &ch,&a[0]);
    c[0] = ch - 'a' + 1;
    n++;
    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
        {
            d[i][j] = 0;
        }
    }
    while (ch != '\n')
    {
        if (scanf("%c", &ch) == EOF) break;
        else
        {
            if (ch != '\n')
            {
                c[n] = ch - 'a' + 1;
                scanf("%d", &a[n]);
            }
            n++;
        }
    }
        for (i = 0; i < (n - 1); i++)
        {
            h = c[i];
            l = a[i];
            d[h - 1][l - 1] = 1;
            if (h < 8) d[h][l - 1] = 1;
            if (h > 1) d[h - 2][l - 1] = 1;
            if (h < 8 && l < 8) d[h][l] = 1;
            if (l < 8) d[h - 1][l] = 1;
            if (l > 1) d[h - 1][l - 2] = 1;
            if (h < 8 && l > 1) d[h][l - 2] = 1;
            if (h > 1 && l < 8) d[h - 2][l] = 1;
            if (h > 1 && l > 1) d[h - 2][l - 2] = 1;
        }
        for (i = 0; i < 8; i++)
        {
            for (j = 0; j < 8; j++)
            {
                if (d[i][j] != 1) fr++;
            }
        }
    printf("%d", fr);
    return 0;
}
