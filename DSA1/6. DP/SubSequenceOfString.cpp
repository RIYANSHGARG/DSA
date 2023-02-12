#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    vector<string> AllStrings;
    cin >> s;
    for (int i = 0; i < (1 << s.length()); i++)
    {
        string temp = "";
        for (int j = 0; j < s.length(); j++)
        {
            if (i & (1 << j))
                temp += s[j];
        }
        AllStrings.push_back(temp);
    }
    for (auto i : AllStrings)
    {
        cout << i << " ";
    }
    return 0;
}