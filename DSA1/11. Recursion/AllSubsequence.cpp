#include <bits/stdc++.h>
using namespace std;

void func(int sv, vector<int> &a, vector<vector<int>> &ans, vector<int> b)
{
    if (sv >= a.size())
    {
        ans.push_back(b);
        return;
    }
    b.push_back(a[sv]);
    func(sv + 1, a, ans, b);
    b.pop_back();
    func(sv + 1, a, ans, b);
}

int main()
{
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int element;
        cin >> element;
        v.push_back(element);
    }
    vector<vector<int>> ans;
    vector<int> dummy;
    func(0, v, ans, dummy);
    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}