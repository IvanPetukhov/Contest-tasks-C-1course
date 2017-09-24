#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct tree
{
    char name[101];
    long long ip;
    struct tree * left;
    struct tree * right;
};

void freetree (struct tree * t)
{
    if (!t)
        return;
    freetree (t->left);
    freetree (t->right);
    free(t);
}

struct tree * plustree (struct tree * t, long long ip, char name[101])
{
    if (!t)
    {
        t = (struct tree *) malloc (sizeof(struct tree));
        t->left = NULL;
        t->right = NULL;
        t->ip = ip;
        strcpy(t->name, name);
    }
    else
    {
        if (strcmp(name, t->name) < 0)
        {
            t->left = plustree(t->left, ip, name);
        }
        else
        {
            t->right = plustree(t->right, ip, name);
        }
    }
    return t;
};

long long search_in_tree (struct tree * t, char name[101])
{
    if (!t)
        return -1;
    while (strcmp(name, t->name) != 0)
    {
        if (strcmp(name, t->name) < 0)
            t = t->left;
        else
            t = t->right;
        if (!t)
            return -1;
    }
    return t->ip;
}

int main(void)
{
    FILE * fp = fopen ("input.txt", "r");
    FILE * fo = fopen ("output.txt", "w");
    int n, m, i;
    struct tree * tr = NULL;
    long long ip;
    char s[101];
    fscanf(fp, "%d", &n);
    for (i = 0; i < n; i++)
    {
        fscanf(fp, "%s", s);
        fscanf(fp, "%lld\n", &ip);
        tr = plustree(tr, ip, s);
    }
    fscanf(fp, "%d", &m);
    for (i = 0; i < m; i++)
    {
        fscanf(fp, "%s", s);
        ip = search_in_tree(tr, s);
        fprintf(fo, "%lld\n", ip);
    }
    fclose(fp);
    fclose(fo);
    freetree(tr);
    return 0;
}

