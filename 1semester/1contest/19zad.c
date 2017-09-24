#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    int k = 31, tr, i;
    unsigned a11, a12, a21, a22, x, y, b1, b2, A11, A12, A21, A22, B1, B2, rezX, rezY;      /*(a11 & x) ^ (a12 & y) = b1    (a21 & x) ^ (a22 & y) = b2*/
    scanf("%u%u%u%u%u%u", &a11, &a12, &a21, &a22, &b1, &b2);
    x = 0;
    y = 0;
    tr = 0;
    rezX = 0;
    rezY = 0;
    for (i = 0; i < 32; i++)
    {
        A11 = a11 << (k - i);
        A11 >>= k;
        A12 = a12 << (k - i);
        A12 >>= k;
        A21 = a21 << (k - i);
        A21 >>= k;
        A22 = a22 << (k - i);
        A22 >>= k;
        B1 = b1 << (k - i);
        B1 >>= k;
        B2 = b2 << (k - i);
        B2 >>= k;
        tr = 0;
        for (x = 0; x <= 1; x++)
        {
            for (y = 0; y <= 1; y++)
            {
                if (( ( (A11 & x) ^ (A12 & y) ) == B1) && (( (A21 & x) ^ (A22 & y)) == B2) && (tr == 0))
                {
                    rezX |= (x << i);
                    rezY |= (y << i);
                    tr = 1;
                }
            }
        }
        if (tr == 0) break;
    }
    if (tr == 1) printf("Yes\n%u %u", rezX, rezY);
        else printf("No");
    return 0;
}
