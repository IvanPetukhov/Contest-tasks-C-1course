#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node
{
    char c;
    struct node *l, *r;
} node;

int prt[128];

void del_tree(node* v)
{
    if(!v)
        return;
    del_tree(v->l);
    del_tree(v->r);
    free(v);
    return;
}

node* gen_tree(char *s)
{
    int i, mi = -1, bal = 0;
    for(i = 0; s[i]; i++)
    {
        if(s[i] == '(')
            bal++;
        if(s[i] == ')')
            bal--;
        if(bal == 1 && prt[s[i]])
        {
            if(mi != -1)
                return 0;
            mi = i;
        }
    }
    if(mi == -1)
    {
        if((s[0] == 'X' || s[0] == 'x' || s[0] >= '0' && s[0] <= '9') && !s[1])
        {
            node* v = (node*)malloc(sizeof(node));
            v->l = v->r = 0;
            v->c = s[0];
            return v;
        }
        return 0;
    }
    node* v = (node*)malloc(sizeof(node));
    v->c = s[mi];
    s[mi] = 0;
    s[i-1] = 0;
    v->l = gen_tree(s+1);
    v->r = gen_tree(s+mi+1);
    if(v->l && v->r)
        return v;
    del_tree(v->l);
    del_tree(v->r);
    free(v);
    return 0;
}

char s[1024*8];
int sr = 0;

void out(node*rt)
{
    if(rt)
    {
        if(rt->c == '-' || rt->c == '+')
        {
            s[sr++] = '(';
            out(rt->l);
            s[sr++] = rt->c;
            out(rt->r);
            s[sr++] = ')';
        }
        else
        {
            out(rt->l);
            s[sr++] = rt->c;
            out(rt->r);
        }
    }
}

void diff(node*rt)
{
    if(rt->c == 'x' || rt->c == 'X')
    {
        s[sr++] = '1';
        return;
    }
    if(rt->c >= '0' && rt->c <= '9')
    {
        s[sr++] = '0';
        return;
    }
    if(rt->c == '+' || rt->c == '-')
    {
        s[sr++] = '(';
        diff(rt->l);
        s[sr++] = rt->c;
        diff(rt->r);
        s[sr++] = ')';
        return;
    }
    if(rt->c == '*')
    {
        s[sr++] = '(';
        s[sr++] = '(';
        diff(rt->l);
        s[sr++] = '*';
        out(rt->r);
        s[sr++] = ')';

        s[sr++] = '+';

        s[sr++] = '(';
        diff(rt->r);
        s[sr++] = '*';
        out(rt->l);
        s[sr++] = ')';
        s[sr++] = ')';
        return;
    }
}

int main(void)
{
    prt['*'] = prt['/'] = 1;
    prt['+'] = prt['-'] = 2;
    fgets(s, sizeof(s), stdin);
    int i, j = 0;
    for(i = 0; s[i]; i++){
        if(s[i] == ' ' || s[i] == '\n' || s[i] == '\r' || s[i] =='\t');
        else if(s[i] == 'x' || s[i] == 'X' || s[i] == '+' || s[i] == '-' || s[i] == '*' ||
                s[i] == '(' || s[i] == ')' || s[i] >= '0' && s[i] <= '9') s[j++] = s[i];
        else
        {
            printf("WRONG SYMBOL");
            return 0;
        }
    }
    s[j] = 0;
    node* rt = gen_tree(s);
    if(!rt)
    {
        printf("ERROR");
        return 0;
    }
    diff(rt);
    del_tree(rt);
    s[sr] = 0;
    puts(s);
    return 0;
}
