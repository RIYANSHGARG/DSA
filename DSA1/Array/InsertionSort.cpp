#include <bits/stdc++.h>
using namespace std;

// Taking a particular element to its correct place by swapping it until it moves to its correct place;
void InsertionSort(vector<int> &v)
{
    for (int i = 1; i < v.size(); i++)
    {
        for (int j = i; j > 0; j--)
        {
            if (v[j] < v[j - 1])
                swap(v[j], v[j - 1]);
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
    InsertionSort(v);
    for (auto i : v)
    {
        cout << i << " ";
    }
    return 0;
}