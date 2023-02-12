// power set algorithm

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 3;
    vector<vector<int>> ans(1 << n);
    int arr[n] = {1, 2, 3};
    for (int i = 0; i < (1 << n); i++)
    {
        vector<int> v;
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                v.push_back(arr[j]);
            }
        }
        ans.push_back(v);
        }
    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j;
        }
        cout << endl;
    }
    return 0;
}