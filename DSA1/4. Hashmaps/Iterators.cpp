#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_map<string, int> m;
    m["abc1"] = 1;
    m["abc2"] = 2;
    m["abc3"] = 3;
    m["abc4"] = 4;
    m["abc5"] = 5;

    unordered_map<string, int>::iterator it = m.begin();
    while (it != m.end())
    {
        cout << it->first << " : " << it->second << endl;
        it++;
    }
    return 0;
}