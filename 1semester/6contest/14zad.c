#include <stdio.h>
#include <stdlib.h>

int read_element(void)
{
    int ch;
    ch = getchar() << 24;
    ch += getchar() << 16;
    ch += getchar() << 8;
    ch += getchar();
    return ch;
}


int main(void)
{
    freopen("matrix.in", "rb", stdin);
    freopen("trace.out", "wb", stdout);
    int n, x;
    long long tr, st;
    n = getchar() << 8;
    n += getchar();
    tr = 0;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
        {
            x = read_element();
            if (i == j)
                  tr += x;
        }
    st = 1 << 6;
    for(int i = 0; i < 8; ++i)
    {
        st -= 8;
        putchar((tr >> st) % 256);
    }
    return 0;
}
