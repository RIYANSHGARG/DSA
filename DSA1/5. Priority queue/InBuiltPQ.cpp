#include <iostream>
#include <queue>
using namespace std;

int main()
{
    priority_queue<int> p;
    p.push(10);
    p.push(50);
    p.push(30);
    p.push(20);
    p.push(5);

    // cout<<p.pop()<<endl;
    cout << p.top() << endl;
    p.pop();
    cout << p.top() << endl;
    cout << p.empty() << endl;
    cout << p.size() << endl;
    return 0;

    priority_queue<int, vector<int>, greater<int>> p; // inbuilt min heap
}