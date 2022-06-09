#include <bits/stdc++.h>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> removeDuplicate(int *a, int size)
{
    vector<int> output = {0};
    unordered_map<int, bool> seen;
    for (int i = 0; i < size; i++)
    {
        if (seen.count(a[i]) > 0)
        {
            // cout << a[i] << endl;
            continue;
        }
        seen.insert({a[i], true});
        // seen[a[i]] = true;
        cout << a[i] << endl;
        output.push_back(a[i]);
    }
    cout << endl;
    return output;
}

int main()
{
    int a[10] = {2, 4, 6, 1, 5, 3, 3, 2, 2, 6};
    vector<int> output = removeDuplicate(a, 10);
    for (auto i : output)
    {
        cout << output[i] << " ";
    }
    return 0;
}