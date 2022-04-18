#include <iostream>
#include <string.h>
#include <stack>

using namespace std;

int main()
{
    string a;
    cin >> a;
    stack<char> s;
    for (int i = 0; i <= a.length(); i++)
    {
        if (a[i] == '(' || a[i] == '{' || a[i] == '[')
        {
            s.push(a[i]);
        }
        else if (a[i] == ')' && s.top() == '(' || a[i] == '}' && s.top() == '{' || a[i] == ']' && s.top() == '[')
        {
            s.pop();
        }
        else
        {
            continue;
        }
    }
    cout << ((s.empty()) ? "Balanced Parenthesis" : "Not Balanced Parenthesis");
    return 0;
}