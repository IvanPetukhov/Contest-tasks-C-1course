#include<stdio.h>
#include<stdlib.h>

int turn(int d)
{
    int k;
    scanf("%d", &k);
    if (k != 0)
        turn(k);
    if (k != 0)
        printf("%d ", k);
    return 0;
}

int main(void)
{
    int i=1;
    turn(i);
    return 0;
}

