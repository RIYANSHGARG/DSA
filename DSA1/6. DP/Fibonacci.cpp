#include <bits/stdc++.h>
using namespace std;

int fibo_1(int n)
{
    if (n <= 1)
    {
        return n;
    }
    int a = fibo_1(n - 1);
    int b = fibo_1(n - 2);
    return a + b;
}

int fibo_2_Helper(int *ans, int n)
{
    if (n <= 1)
    {
        return n;
    }

    if (ans[n] != -1)
    {
        return ans[n];
    }
    int a = fibo_2_Helper(ans, n - 1);
    int b = fibo_2_Helper(ans, n - 2);

    ans[n] = a + b;
    return ans[n];
}

int fibo_2(int n)
{
    int *ans = new int[n + 1];
    for (int i = 0; i <= n; i++)
    {
        ans[i] = -1;
    }
    return fibo_2_Helper(ans, n);
}

int fibo_3(int n)
{
    int *ans = new int[n + 1];
    ans[0] = 0;
    ans[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        ans[i] = ans[i - 1] + ans[i - 2];
    }

    return ans[n];
}

int main()
{
    int ans = fibo_3(6);
    cout << ans;
    return 0;
}