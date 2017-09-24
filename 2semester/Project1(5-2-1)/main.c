#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f1(double x)
{
    return (0.35 * x * x - 0.95 * x + 2.7);
}

double f2(double x)
{
    return (pow(3.0, x) + 1);
}

double f3(double x)
{
    return (1 / (x + 2));
}

double deltaf(double (*f)(double), double (*g)(double), double x)
{
    return ((*f)(x) - (*g)(x));
}

double root_hord(double(*f)(double), double(*g)(double), double a, double b, double eps1)
{
    double deltaf_a;
    deltaf_a = deltaf(f, g, a);
    double deltaf_b;
    deltaf_b = deltaf(f, g, b);
    double c;
    c = (a * deltaf_b - b * deltaf_a) / (deltaf_b - deltaf_a);
    double deltaf_c;
    deltaf_c = deltaf(f, g, c);
    if (((deltaf_c * deltaf(f, g, (c + eps1/2))) < 0) || ((deltaf_c * deltaf(f, g, (c - eps1/2))) < 0))
        return c;
    if (deltaf_a < 0 && deltaf(f, g, ((a + b) / 2)) < ((deltaf_a + deltaf_b) / 2))
        a = c;
    else
        if (deltaf_a > 0 && deltaf(f, g, (a + b) / 2) > ((deltaf_a + deltaf_b) / 2))
            a = c;
    else
        b = c;
    return root_hord(f, g, a, b, eps1);
}

double integral_n (double (*f)( double), double a, double b, int n)
{
    double result;
    result = 0.0;
    double h;
    h = (b - a) / (double) n;
    int i;
    for(i =0; i< n; i++)
    {
        result += f (a + (i + 0.5) * h);
    }
    result *= h;
    return result;
}

double integral (double (*f)( double), double a, double b, double eps2)
{
    if (a > b)
    {
        double t;
        t = a;
        a = b;
        b = t;
    }
    int n = 20;
    double I0, In, delta;
    do
    {
        I0 = integral_n (f, a, b, n);
        n = 2 * n;
        In = integral_n (f, a, b, n);
        delta = (I0 - In) / 3.0;
        if (delta < 0)
            delta = -delta;
    } while (delta > eps2);
    return In;
}

int main(void)
{
    double eps1 = 0.00001;
    double eps2 = 0.00001;
    double x1, x2, x3, s1, s2, s3, S;
    double a, b;
    scanf("%lf %lf", &a, &b);
    x1 = root_hord(f1, f2, a, b, eps1);
    x2 = root_hord(f1, f3, a, b, eps1);
    x3 = root_hord(f2, f3, a, b, eps1);
    printf("x1 = %.3lf  x2 = %.3lf  x3 = %.3lf\n", x1, x2, x3);
    s1 = integral(f1, x1, x2, eps2);
    s2 = integral(f2, x2, x3, eps2);
    s3 = integral(f3, x1, x3, eps2);
    S = s1-s2-s3;
    printf("ploshad = %.3lf", S);
    return 0;
}
