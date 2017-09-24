void shellsort(int l[], int n, int r[])
{
int j, i, mid, L, R;
for(mid = n / 2; mid > 0; mid /= 2)
{
    for(j = mid; j < n; j++)
    {
        for( i = j - mid; i >= 0; i -= mid)
        {
            if(l[i + mid] >= l[i])
            break;
            else
            {
                L = l[i];
                l[i] = l[i + mid];
                l[i + mid] = L;
                R = r[i];
                r[i] = r[i + mid];
                r[i + mid] = R;

            }
        }
    }
}
}
