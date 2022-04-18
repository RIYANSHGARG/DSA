#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int size;
    cin >> size;
    int a[size], b[size];
    stack<int> s;
    for (int i = 0; i < size; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < size; i++)
    {
        if (s.empty() || a[s.top()] > a[i])
        {
            s.push(i);
            b[i] = 1;
        }
        else
        {
            while (a[s.top()] < a[i] && s.empty() != 1)
            {
                s.pop();
            }

            if (s.empty())
            {
                b[i] = i + 1;
                s.push(i);
            }
            else
            {
                b[i] = i - s.top();
                s.push(i);
            }
        }
    }
    for (int i = 0; i < size; i++)
    {
        cout << b[i] << " ";
    }
    return 0;
}