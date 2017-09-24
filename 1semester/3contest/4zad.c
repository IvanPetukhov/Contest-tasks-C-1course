#include<stdio.h>
#include<stdlib.h>

int turn(int i)
{
    int k;
    scanf("%d", &k);
    if ((i % 2 == 1) && (k != 0))
        printf("%d ", k);
    if (k == 0) return 0;
    i++;
    turn(i);
    i--;
    if ((i % 2 == 0) && (k != 0)) printf("%d ", k);
    i--;
    return 0;
}

int main(void)
{
    int d = 1;
    turn(d);
    return 0;
}

