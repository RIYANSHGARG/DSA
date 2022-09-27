#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int> &v)
{
    for (int i = 0; i < v.size() - 1; i++)
    {
        for (int j = 0; j < v.size() - i - 1; j++)
        {
            if (v[j] > v[j + 1])
                swap(v[j], v[j + 1]);
        }
    }
}

int main()
{
    int size;
    cin >> size;
    vector<int> v;
    for (int i = 0; i < size; i++)
    {
        int element;
        cin >> element;
        v.push_back(element);
    }
    bubbleSort(v);
    for (auto i : v)
    {
        cout << i << " ";
    }
    return 0;
}