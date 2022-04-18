#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int count = 0, size;
    stack<int> s;
    stack<int> s1;
    cin >> size;
    while (count != size - 1)
    {
        int element;
        cin >> element;
        s.push(element);
        count++;
    }
    while (s.empty() != 1)
    {
        s1.push(s.top());
        s.pop();
    }
    cout << s1.top();
    return 0;
}