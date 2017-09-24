#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int isempty(char * st, int l)
{
    int i;
    for (i = 0; i < l; i++)
        if ((st[i] != ' ') && (st[i] != '\n'))
            return 0;
    return 1;
}

int main (void)
{
    FILE * fp = fopen("input.txt", "r");
    if (!fp)
        return 0;
    FILE * fo = fopen ("output.txt", "w");
    if (!fo)
        return 0;
    char st[20001];
    int t = 1, l, per = 0;
    int s = 0, r = 0, w = 0;
    while (fgets(st, 20000, fp) != NULL)
    {
        l = strlen(st);
        if (st[l - 1] == '\n')
        {
            l--;
        }
        if (isempty(st, l) == 1)
        {
            t = 1;
        }
        else
        {
            if (t == 1)
            {
                t = 0;
                r++;
            }
            int now = 0;
            int pos = 0;
            while (now != -1)
            {
                if (now == 0)
                {
                    while ((pos < l) && (st[pos] == ' '))
                        pos++;
                    if (pos == l)
                    {
                        now = -1;
                    }
                    else
                    {
                        now = 1;
                    }
                }
                else if (now == 1)
                {
                    if (st[pos] == '.')
                    {
                        s++;
                        pos++;
                        now = 0;
                    }
                    else
                    {
                        if (!per)
                        {
                            w++;
                        }
                        per = 0;
                        while ((pos < l) && (((st[pos] >= 'a') && (st[pos] <= 'z'))
                            || ((st[pos] >= 'A') && (st[pos] <= 'Z')) || (st[pos] == '-')))
                        {
                                pos++;
                        }
                        if (pos < l)
                        {
                            now = 0;
                        }
                        else
                        {
                            if (st[l - 1] == '-')
                            {
                                per = 1;
                            }
                            now = -1;
                        }
                    }
                }
            }
        }
    }
    fprintf(fo, "%d %d %d", w, s, r);
    fclose(fp);
    fclose(fo);
    return 0;
}

