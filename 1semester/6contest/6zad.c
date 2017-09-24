#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct listnode
{
    int a;
    struct listnode * next;
};

void add_to_list (struct listnode ** head, int x)
{
    if (*head == NULL)
    {
        *head = (struct listnode *)malloc(sizeof(struct listnode));
        (*head)->a = x;
        (*head)->next = NULL;
    }
    else
    {
        struct listnode * list = *head;
        while (list->next != NULL)
        {
            list = list->next;
        }
        list->next = (struct listnode *)malloc(sizeof(struct listnode));
        list->next->a = x;
        list->next->next = NULL;
    }
    return;
}

void delete_list(struct listnode ** head)
{
    struct listnode * list = *head;
    while (list != NULL)
    {
        struct listnode * new_list = list->next;
        free(list);
        list = new_list;
    }
    return;
}

int isfound (struct listnode ** head, int x)
{
    struct listnode *list = *head;
    while (list != NULL)
    {
        if (list->a == x)
            return 1;
        else
            list = list->next;
    }
    return 0;
}

int main (void)
{
    FILE * fp = fopen("input.txt", "r");
    if (!fp)
        return 0;
    FILE * fo = fopen ("output.txt", "w");
    if (!fo)
        return 0;
    int x;
    struct listnode * head1 = 0, * head2 = 0;
    fscanf(fp, "%d", &x);
    while (x != -1)
    {
        add_to_list(&head1, x);
        fscanf(fp, "%d", &x);
    }
    fscanf(fp, "%d", &x);
    while (x != -1)
    {
        add_to_list(&head2, x);
        fscanf(fp, "%d", &x);
    }
    struct listnode *searching = head1;
    while (searching != NULL)
    {
        if (isfound(&head2,searching->a) == 0)
            fprintf(fo, "%d ", searching->a);
        searching = searching->next;
    }
    delete_list(&head1);
    delete_list(&head2);
    fclose(fp);
    fclose(fo);
    return 0;
}

