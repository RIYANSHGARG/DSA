#include <bits/stdc++.h>

using namespace std;

void recursion(int i, vector<int> &v, vector<vector<int>> &ans, vector<int> temp)
{
    if (i >= v.size())
    {
        ans.push_back(temp);
        return;
    }
    temp.push_back(v[i]);
    recursion(i + 1, v, ans, temp);
    temp.pop_back();
    recursion(i + 1, v, ans, temp);
}

void recursion2(int i, vector<int> &v, vector<vector<int>> &ans, vector<int> temp)
{
    if (i >= v.size())
    {
        ans.push_back(temp);
        return;
    }
    // temp.push_back(v[i]);
    recursion(i + 1, v, ans, temp);
    temp.push_back(v[i]);
    recursion(i + 1, v, ans, temp);
}

void recursion3(int i, vector<int> &v, vector<vector<int>> &ans, vector<int> temp)
{
    if (i < 0)
        return;
    // temp.push_back(v[i]);
    recursion(i - 1, v, ans, temp);
    temp.push_back(v[i]);
    recursion(i - 1, v, ans, temp);
}

void recursion4(int i, vector<int> &v, vector<vector<int>> &ans, vector<int> &temp)
{
    if (i < 0)
        return;
    temp.push_back(v[i]);
    recursion(i - 1, v, ans, temp);
    temp.pop_back();
    recursion(i - 1, v, ans, temp);
}

void print(vector<vector<int>> ans)
{
    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

int main()
{
    vector<int> v;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int element;
        cin >> element;
        v.push_back(element);
    }

    vector<vector<int>> ans, ans2, ans3, ans4;
    vector<int> temp;
    // recursion(0,v,ans,temp);
    print(ans);

    // recursion2(0, v, ans2, temp);
    // print(ans2);

    // recursion3(v.size() - 1, v, ans3, temp);
    // print(ans3);

    recursion4(v.size() - 1, v, ans4, temp);
    print(ans4);
    return 0;
}