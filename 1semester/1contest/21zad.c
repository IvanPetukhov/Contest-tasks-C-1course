#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    long long int N, mass1, mass2, sumgir, kolvo, ves1, ves2, gir;
    scanf("%lld", &N);
    ves1 = N;
    gir = 1;
    ves2 = 0;
    mass1 = N;
    mass2 = 0;
    kolvo = 0;
    while (N != 0)
    {
        gir = 1;
        sumgir = 1;
        while (N > sumgir)
        {
            gir *= 3;
            sumgir += gir;
        }
        if (ves1 < ves2)
        {
            ves1 += gir;
            mass1 += gir;
        }
        else
        {
            ves2 += gir;
            mass2 += gir;
        }
        if (N < gir)
        {
            ves1 -= N;
            ves2 -= N;
        }
        else
        {
            ves1 -= gir;
            ves2 -= gir;
        }
        if (ves1 <= ves2) N = ves2;
        else N = ves1;
        kolvo++;
    }
    if (mass1 <= 1000000 && mass2 <= 1000000)
        printf("%lld", kolvo);
    else
        printf("-1");
    return 0;
}
