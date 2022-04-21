#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
    string s;
    cin >> s;
    stack<char> a;
    for (int i = 0; i < s.length(); i++)
    {
        char b = s[i];
        if (b == '[' || b == '{' || b == '(')
        {
            a.push(s[i]);
        }
        else
        {
            char x = a.top();

            if (x == '(' && b == ')' || x == '{' && b == '}' || x == '[' && b == ']')
            {
                a.pop();
            }
        }
    }
    if (a.empty())
    {
        cout << "sucess";
    }
    else
    {
        cout << "failure";
    }
    return 0;
}