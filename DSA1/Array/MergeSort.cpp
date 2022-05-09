#include <iostream>

using namespace std;

int *Merge(int *b, int n1, int *c, int n2)
{

    int d[n1 + n2];
    while (b[i] > c[j])
    {
        i++;
    }
    while (b[i] < c[j])
    {
        j++;
    }

    for (int i = 0, j = 0; i < n1, j < n2; i++, j++)
    {
        if (b[i] < c[j])
        {
            d[]
        }
    }
}

int *MergeSort(int *a, int s, int e)
{
    if (s > e)
    {
        return NULL;
    }

    int *b = MergeSort(a, s, (s + e) / 2);
    int *c = MergeSort(a, ((s + e) / 2) + 1, e);

    a = Merge(b, ((s + e) / 2), c, ((s + e + 1) / 2));
}

int main()
{
    int a[6] = {2, 1, 4, 3, 5, 6} a = MergeSort(a, 0, 5);
    return 0;
}