#include <iostream>
using namespace std;

int func(int a)
{
    if (a < 2)
        return a;
    return a * func(a - 1);
}
int main()
{
    int n;
    cin >> n;
    int a = func(n);
    cout << a;
    return 0;
}