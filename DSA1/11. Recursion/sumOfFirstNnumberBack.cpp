#include <iostream>

using namespace std;
int recursion(int a, int sum)
{
    if (a < 1)
        return 0;
    sum = a + recursion(a - 1, sum);
    return sum;
}

int main()
{
    int n, sum = 0;
    cin >> n;
    int a = recursion(n, sum);
    cout << a;
    return 0;
}