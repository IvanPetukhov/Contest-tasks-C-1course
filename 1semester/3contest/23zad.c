#include<stdio.h>
#include<stdlib.h>

//Group: 102
//Petukhov Ivan
//Task #23 of 3 contest
//Regular pyramid
/*
Regular pyramid on the coordinate plane is defined by the following conditions.
This pyramid consists of tiers(one above the other).
Each tier should consist of square blocks of equal size,
arranged in one line. The length of the respective tiers is
the product of the block size and the number of blocks in the tier.
In the right pyramid, the length of all lines except the tier -
base strictly less than the length of the lower tiers.
Furthermore, each overlying a pyramid stage comprises
one unit less than the underlying tier, and this is always at the top
of the pyramid is a tier of blocks. Required to determine whether
a given set of blocks to build the right pyramid , using all specified blocks.

On the standard input stream is given a natural number M (M < 19 ),
and further pairs of positive integers M S[i], C[i],
where S[i] - the size of the unit (S[i] < 10000 ),
C[i] - the number of blocks of size SxS, and S[i] <S[i] +1 for all allowable i.
It is also known that the sum of C[i] < 200.

To the standard output , type "Yes", if we can construct a regular pyramid , and "No" otherwise.
*/
int tier(long int s[], long int c[], long int M, long int blocks_in_tier, long int length_of_lower_tier)
{
    int i = 0, save;
    if (blocks_in_tier == 0)
    {
        return 1;
    }
    for (i = 0; i < M; i++)
    {
        if (c[i] >= blocks_in_tier)
        {
            if ((s[i] * blocks_in_tier) < length_of_lower_tier)
            {
                save = c[i];
                c[i] = c[i] - blocks_in_tier;
                if (tier(s, c, M, (blocks_in_tier - 1), (s[i] * blocks_in_tier)) != 0)
                {
                    return 1;
                }
                c[i] = save;
            }
        }
    }
    return 0;
}

int main(void)
{
    long int M, i, k = 1, amount = 0, blocks_needed = 0;
    scanf("%ld", &M);
    long int s[M], c[M];
    for (i = 0; i < M; i++)
    {
        scanf("%ld%ld", &s[i], &c[i]);
        amount = amount + c[i];
    }
    while (amount > blocks_needed)
    {
        blocks_needed += k;
        k++;
    }
    if (blocks_needed == amount)
    {
        k--;
        if (tier(s, c, M, k, 1000000000) != 0)
            printf("Yes");
        else
            printf("No");
    }
    else
        printf("No");
    return 0;
}

