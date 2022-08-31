#include <iostream>

using namespace std;

int *Merge(int *b, int n1, int *c, int n2)
{

    int i = 0, j = 0, k = 0;
    int *d = new int[n1 + n2];
    while (i < n1 && j < n2)
    {
        if (b[i] <= c[j])
        {
            cout << d[k];

            d[k] = b[i];
            i++;
        }
        else
        {
            cout << d[k];
            d[k] = c[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        d[k] = b[i];
        i++;
        k++;
    }
    while (i < n2)
    {
        d[k] = c[i];
        i++;
        k++;
    }
    return d;
}

int *MergeSort(int *a, int s, int e)
{
    if (s > e)
    {
        return NULL;
    }

    int *b = MergeSort(a, s, (s + e) / 2);
    int *c = MergeSort(a, ((s + e) / 2) + 1, e);

    int *d = Merge(b, ((s + e) / 2), c, ((s + e + 1) / 2));
    return d;
}

int main()
{
    int a[6] = {2, 1, 4, 3, 5, 6};
    int *b = MergeSort(a, 0, 5);
    for (int i = 0; i < 6; i++)
    {
        cout << b[i];
    }
    return 0;
}