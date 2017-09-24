#include<stdio.h>
#include<stdlib.h>

#define O 0.000001
double ** a;
double * b;
int n;
double * x;
FILE * fp;

void CreateMatrix(int n)
{
    int i, j;
    a = (double **) malloc (n * sizeof (double *));
    b = (double *) malloc (n * sizeof (double));
    x = (double *) malloc (n * sizeof (double));
    for (i = 0; i < n; i++)
    {
        a[i] = (double *) malloc (n * sizeof (double));
        for (j = 0; j < n; j++)
            fscanf(fp, "%lf", &a[i][j]);
        fscanf(fp, "%lf", &b[i]);
    }
    return;
}

void DeleteMatrix (void)
{
    int i;
    for (i = 0; i < n; i++)
        free(a[i]);
    free(a);
    free(b);
    free(x);
    return;
}

void SwapRows (int x, int y)
{
    int i, t = 0;
    for (i = 0; i < n; i++)
    {
         t = a[x][i];
         a[x][i] = a[y][i];
         a[y][i] = t;
    }
    return;
}

void Swap_B (int x, int y)
{
    int t;
    t = b[x];
    b[x] = b[y];
    b[y] = t;
    return;
}

void DivideRow (int x, double del)
{
    int i;
    if ((del > O) || (del < O))
    {
        for (i = 0; i < n; i++)
            a[x][i] = a[x][i] / del;
        b[x] = b[x] / del;
    }
    return;
}
double mod(double x)
{
    if (x < -O)
        return (-x);
    return x;
}

void Gauss(int n)
{
    int i, j, h, k;
    int row = 0;
    double max_ai = O, t;
    for (i = 0; i < n; i++)
    {
        max_ai=O;
        for (j = i; j < n; j++)
        {
            if (mod (a[j][i]) > max_ai)
            {
                max_ai = mod (a[j][i]);
                row = j;
            }
        }
        if (row != i)
        {
            SwapRows(row, i);
            Swap_B(row, i);
        }
        DivideRow(i, a[i][i]);
        for (h = i + 1; h < n; h++)
        {
            t = a[h][i];
            b[h] = b[h] - t * b[i];
            for (k = i; k < n; k++)
            {
                a[h][k] = a[h][k] - t * a[i][k];
                printf ("%.0lf ", a[h][k]);
            }
            printf("\n");
        }
    }
    for (i = n - 1; i >= 0; i--)
    {
        x[i] = b[i];
        for(j = i + 1; j < n; j++)
            x[i] = x[i] - a[i][j] * x[j];
    }
}

int main(void)
{
    int i;
    fp = fopen("input.txt", "r");

    fscanf(fp, "%d", &n);
    CreateMatrix(n);
    Gauss(n);
    for (i = 0; i < n; i++)
        printf ("%.0lf\n", x[i]);
    DeleteMatrix();
    fclose(fp);
    return 0;
}

