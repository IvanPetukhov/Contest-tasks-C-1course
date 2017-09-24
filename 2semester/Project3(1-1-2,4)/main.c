#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define c 1000   //defining N

unsigned long long count_compare = 0; //counting compares
unsigned long long count_move = 0; //counting moves

unsigned long long t0 = 0; //timing in the beginning of the sorting
unsigned long long t1 = 0; //timing in the end of the sorting
extern unsigned long long timestamp(void); //counting time function
extern int compare (int a, int b); //returns 1 if a < b, returns 0 otherwise
extern void swap (int * a, int * b); // changes the values of a and b

void fillrandom (int * a, int * b, int n) //filling arrays a and b with random numbers
{
    int i;
    for (i = 0; i < n; i++)
    {
        a[i] = rand () * rand() / rand();
        b[i] = a[i];
    }
    return;
}

void fillright (int * a, int * b,  int n) //filling arrays a and b with numbers in the right order
{
    int i;
    for (i = 0; i < n; i++)
    {
        a[i] = i;
        b[i] = i;
    }
    return;
}

void fillreverse (int * a, int * b, int n) //filling arrays a and b with numbers in the reversed order
{
    int i;
    for (i = 0; i < n; i++)
    {
        a[i] = n - i - 1;
        b[i] = n - i - 1;
    }
    return;
}

void quicksort(int * a, int k, int n) // Quick sort
{
    int comp;
    int i, j;
    i = k;
    j = n - 1;
    comp = a[(i + j) / 2];
    do{
        while (compare(a[i], comp))
            i++;
        while (compare(comp, a[j]))
            j--;
        if(i <= j)
        {
            swap(&a[i], &a[j]);
            i++;
            j--;
        }
    } while(i <= j);

    if(k < j)
        quicksort(a, k, j);
    if(i < n)
        quicksort(a, i, n);
    return;
}

void SelectSort(int *a, int n) //Simple Select Sort
{
    int i;
    int j;
    for (i = 0; i < (n - 1); i++)
    {
        int minn = i;
        for (j = i + 1; j < n; j++)
        {
            if (compare(a[j], a[minn]))
            {
                minn = j;
            }
        }
        swap (&a[i], &a[minn]);
    }
    return;
}

int main(void)
{
    int *a = (int *) malloc (sizeof(int) * c); //creating array a
    int *b = (int *) malloc (sizeof(int) * c); //creating array b

    srand (time (NULL));

    //with right
    //Select Sort
    count_compare = 0;
    count_move = 0;
    t0 = timestamp();
    fillright (a, b, c);
//printf("\n");
//for(int i = 0; i < c; i++)
//printf("%d  ", a[i]);
    SelectSort (a, c);
//printf("\n");
//for(int i = 0; i < c; i++)
//printf("%d  ", a[i]);
    t1 = timestamp() - t0;
    printf("\n");
    printf("Select Sort:\n");
    printf("Number of compares:  %llu\n", count_compare);
    printf("Number of moves:  %llu\n", count_move);
    printf("Time:  %llu\n", t1);

    //Quick Sort
    count_compare = 0;
    count_move = 0;
    t0 = timestamp();
//printf("\n");
//for(int i = 0; i < c; i++)
//printf("%d  ", b[i]);
    quicksort (b, 0, c);
//printf("\n");
//for(int i = 0; i < c; i++)
//printf("%d  ", b[i]);
    t1 = timestamp() - t0;
    printf("\n");
    printf("Quick Sort:\n");
    printf("Number of compares:  %llu\n", count_compare);
    printf("Number of moves:  %llu\n", count_move);
    printf("Time:  %llu\n", t1);

    //with reverse
    //Select Sort
    count_compare = 0;
    count_move = 0;
    t0 = timestamp();
    fillreverse (a, b, c);
//printf("\n");
//for(int i = 0; i < c; i++)
//printf("%d  ", a[i]);
    SelectSort (a, c);
//printf("\n");
//for(int i = 0; i < c; i++)
//printf("%d  ", a[i]);
    t1 = timestamp() - t0;
    printf("\n");
    printf("Select Sort:\n");
    printf("Number of compares:  %llu\n", count_compare);
    printf("Number of moves:  %llu\n", count_move);
    printf("Time:  %llu\n", t1);

    //Quick Sort
    count_compare = 0;
    count_move = 0;
    t0 = timestamp();
//printf("\n");
//for(int i = 0; i < c; i++)
//printf("%d  ", b[i]);
    quicksort (b, 0, c);
//printf("\n");
//for(int i = 0; i < c; i++)
//printf("%d  ", b[i]);
    t1 = timestamp() - t0;
    printf("\n");
    printf("Quick Sort:\n");
    printf("Number of compares:  %llu\n", count_compare);
    printf("Number of moves:  %llu\n", count_move);
    printf("Time:  %llu\n", t1);

    //with random
    //Select Sort
    count_compare = 0;
    count_move = 0;
    t0 = timestamp();
    fillrandom (a, b, c);
//printf("\n");
//for(int i = 0; i < c; i++)
//printf("%d  ", a[i]);
    SelectSort (a, c);
//printf("\n");
//for(int i = 0; i < c; i++)
//printf("%d  ", a[i]);
    t1 = timestamp() - t0;
    printf("\n");
    printf("Select Sort:\n");
    printf("Number of compares:  %llu\n", count_compare);
    printf("Number of moves:  %llu\n", count_move);
    printf("Time:  %llu\n", t1);

    //Quick Sort
    count_compare = 0;
    count_move = 0;
    t0 = timestamp();
//printf("\n");
//for(int i = 0; i < c; i++)
//printf("%d  ", b[i]);
    quicksort (b, 0, c);
//printf("\n");
//for(int i = 0; i < c; i++)
//printf("%d  ", b[i]);
    t1 = timestamp() - t0;
    printf("\n");
    printf("Quick Sort:\n");
    printf("Number of compares:  %llu\n", count_compare);
    printf("Number of moves:  %llu\n", count_move);
    printf("Time:  %llu\n", t1);

    //with random
    //Select Sort
    count_compare = 0;
    count_move = 0;
    t0 = timestamp();
    fillrandom (a, b, c);
//printf("\n");
//for(int i = 0; i < c; i++)
//printf("%d  ", a[i]);
    SelectSort (a, c);
//printf("\n");
//for(int i = 0; i < c; i++)
//printf("%d  ", a[i]);
    t1 = timestamp() - t0;
    printf("\n");
    printf("Select Sort:\n");
    printf("Number of compares:  %llu\n", count_compare);
    printf("Number of moves:  %llu\n", count_move);
    printf("Time:  %llu\n", t1);

    //Quick Sort
    count_compare = 0;
    count_move = 0;
    t0 = timestamp();
//printf("\n");
//for(int i = 0; i < c; i++)
//printf("%d  ", b[i]);
    quicksort (b, 0, c);
//printf("\n");
//for(int i = 0; i < c; i++)
//printf("%d  ", b[i]);
    t1 = timestamp() - t0;
    printf("\n");
    printf("Quick Sort:\n");
    printf("Number of compares:  %llu\n", count_compare);
    printf("Number of moves:  %llu\n", count_move);
    printf("Time:  %llu\n", t1);

    free(a);
    free(b);

    return 0;
}
