#include <iostream>
using namespace std;

void func(vector<int> &c, vector<vector<int>> &ans, vector<int> &v, int i, int target)
{

    if (i == c.size())
    {
        if (target == 0)
            ans.push_back(v);
        return;
    }

    if (c[i] < target)
    {
        v.push_back(c[i]);
        func(c, ans, v, i, target);
    }
    else
    {
        v.pop_back();
        func(c, ans, v, i + 1, target);
    }
}

int main()
{
    int n, target = 0;
    cin >> n;
    vector<int> ques;
    for (int i = 0; i < ; i++)
    {
        int element;
        cin >> element;
        ques.push_back(element);
    }
    cin >> target;
    int index = 0;
    vector<vector<int>> ans;
    vector<int> v;
    func(ques, ans, v, index, target);
    return 0;
}