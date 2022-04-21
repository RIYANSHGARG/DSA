#include <iostream>
#include <stack>
using namespace std;

int main()
{
    string a;
    cin >> a;
    stack<char> s;
    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] == '{')
        {
            s.push(a[i]);
        }
        else if (a[i] == '}')
        {
            s.pop();
        }
        else
        {
            continue;
        }
    }
    if (s.size() % 2 == 0)
    {
        cout << s.size() / 2;
    }
    else
    {
        cout << "-1";
    }
    return 0;
}