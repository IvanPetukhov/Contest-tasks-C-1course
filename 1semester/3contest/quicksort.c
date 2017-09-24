void Sort(int l[], int left, int right, int r[])
{
    int i = left, j = right;
    int tmp, k;
    int pivot = l[(left + right) / 2];
    while (i <= j)
    {
        while (l[i] < pivot)
        {
            i++;
        }
        while (l[j] > pivot)
        {
            j--;
        }
        if (i <= j)
        {
            tmp = l[i];
            l[i] = l[j];
            l[j] = tmp;
            k = r[i];
            r[i] = r[j];
            r[j] = k;
            i++;
            j--;
        }
    }
    if (left < j)
    Sort(l, left, j, r);
    if (i < right)
    Sort(l, i, right, r);
}
