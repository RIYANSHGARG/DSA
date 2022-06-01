#include <bits/stdc++.h>
// #include <unordered_map>
using namespace std;

int main()
{
    unordered_map<string, int> m;
    m["abc"] = 2;
    cout << m.at("abc") << endl;
    cout << m.size() << endl;
    cout << m.count("abc") << endl;
    m.erase("abc");
    cout << m.size() << endl;
    cout << m.count("abc") << endl;
    return 0;
}