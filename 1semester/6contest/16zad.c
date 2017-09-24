#include <stdio.h>
#include <stdlib.h>

struct listnode
{
    int key;
    struct listnode * next;
};

struct listnode * mergesort (struct listnode * head, int length)
{
    struct listnode * L, * L1, * head_new;
    int j;
    L = head;
    head_new = (struct listnode *) malloc (sizeof (struct listnode));
    if (length <= 1)
        return head;
    for (j = length/2 - 1; j > 0; j--)
    {
        L = L->next;
    }
    L1 = L;
    L = L->next;
    L1->next = NULL;
    head = mergesort(head, length/2);
    L = mergesort(L, length - length/2);
    L1 = head_new;
    while (L != NULL && head != NULL)
    {
        if (head->key <= L->key)
        {
            L1->next = head;
            head = head->next;
            L1 = L1->next;
        }
        else
        {
            L1->next = L;
            L = L->next;
            L1 = L1->next;
        }
    }
    if (L != NULL)
    {
        L1->next = L;
    }
    else if (head != NULL)
    {
        L1->next = head;
    }
    L1 = head_new;
    head_new = head_new->next;
    free (L1);
    return head_new;
}

int main(void)
{
    struct listnode * head, * L, * L1;
    int i = 0, k = 0;
    int j;
    FILE * fp = fopen("input.txt", "r");
    FILE * fo = fopen ("output.txt", "w");
    head = (struct listnode *) malloc (sizeof(struct listnode));
    L = head;
    head->next = NULL;
    while ( fscanf (fp, "%d", &k) != EOF)
    {
        L->next = (struct listnode *) malloc (sizeof (struct listnode));
        L = L->next;
        L->key = k;
        i++;
    }
    L->next = NULL;
    L = head;
    head->next = mergesort(head->next, i);
    L = head;
    for (j = 1; j <= i; j++)
    {
        L1 = L;
        L = L->next;
        fprintf (fo, "%d ", L->key);
        free (L1);
    }
    free (L);
    fclose (fp);
    fclose (fo);
    return 0;
}
