#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int size, count = 1;
    cin >> size;
    int a[size], b[size];
    stack<int> s;
    for (int i = 0; i < size; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < size; i++)
    {
        if (s.empty() || s.top() > a[i])
        {
            s.push(a[i]);
            b[i] = count;
        }
        else
        {
            stack<int> s1(s);
            while (s1.top() < a[i])
            {
                s1.pop();
                count++;
            }
            b[i] = count;
            count = 1;
        }
    }
    for (int i = 0; i < size; i++)
    {
        cout << b[i] << " ";
    }
    return 0;
}