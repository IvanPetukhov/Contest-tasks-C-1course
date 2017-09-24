#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *mas;
    int len = 100;
    mas = (int *) malloc (sizeof(int) * len);
    int i = 0, k = 0;

    scanf("%d", &mas[0]);
    if (mas[0]) printf("%d ",mas[0]);
    while(mas[i]){
        i++;
        scanf("%d", &mas[i]);
        if(len == i+1){
            len = len * 2;
            mas = realloc (mas, sizeof(int) * len);
        }

        if ((i % 2 == 0) && (mas[i]))
        printf("%d ", mas[i]);
    }

    for(k = 0; k < i; k++)
        if (k % 2 == 1)
            printf("%d ", mas[k]);
    free(mas);
    return 0;
}

