#include <iostream>
#include <bits/stdc++.h>
#include <unordered_map>
#include <vector>
using namespace std;

int main()
{
    int a[10] = {2, 4, 1, 3, 2, 2, 4, 3, 2, 4};
    // int max = 0, count = 0;
    // vector<int> v;
    // for (int i = 0; i < 10; i++)
    // {
    //     v[a[i]] = v[i] + 1;
    // }
    // for (auto i : v)
    // {
    //     cout << v[i] << " ";
    // }
    // int index = *max_element(v.begin(), v.end());
    // cout << a[index];
    int maxfreq = 0, value = 0;
    unordered_map<int, int> map;
    for (int i = 0; i < 10; i++)
    {
        if (map.count(a[i]) > 0)
        {
            map[a[i]]++;
            if (map[a[i]] > maxfreq)
            {
                maxfreq = map[a[i]];
            }
        }
        map[a[i]] = 1;
    }
    return 0;
}