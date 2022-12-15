#include <bits/stdc++.h>
using namespace std;

// Find the min. Element and then swap it;
void SelectionSort(vector<int> &v)
{
    for (int i = 0; i < v.size() - 1; i++)
    {
        int min_ele = min(v.begin(), v.end() - i);
        if (v[i] > min_ele)
            swap(v[i], min_ele);
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
    SelectionSort(v);
    for (auto i : v)
    {
        cout << i << " ";
    }
    return 0;
}