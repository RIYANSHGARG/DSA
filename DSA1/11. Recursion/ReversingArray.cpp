#include <iostream>
using namespace std;

void func(int *a, int si, int ei)
{
    if (si >= ei)
        return;
    func(a, si + 1, ei - 1);
    swap(a[si], a[ei]);
}

int main()
{
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    func(a, 0, 9);
    for (int i = 0; i < 10; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}