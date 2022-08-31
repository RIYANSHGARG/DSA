#include <bits/stdc++.h>
#include <climits>
using namespace std;

int MinStep(int n)
{
    if (n == 1)
    {
        return 0;
    }

    int a = MinStep(n - 1);
    int b = INT_MAX, c = INT_MAX;
    if (n % 2 == 0)
    {
        b = MinStep(n / 2);
    }
    if (n % 3 == 0)
    {
        c = MinStep(n / 3);
    }

    int d = min(a, min(b, c));
    return d + 1;
}

int MinStep_2_Helper(int n, int *ans)
{
    if (n == 1)
    {
        return 0;
    }
    if (ans[n - 1] != -1)
    {
        return ans[n - 1];
    }

    int a = MinStep(n - 1);
    int b = INT_MAX, c = INT_MAX;
    if (n % 2 == 0)
    {
        b = MinStep(n / 2);
    }
    if (n % 3 == 0)
    {
        c = MinStep(n / 3);
    }

    int d = min(a, min(b, c));
    ans[n - 1] = d + 1;
    return ans[n - 1];
}

int MinStep_2(int n)
{
    int *ans = new int[n - 1];
    for (int i = 0; i < n; i++)
    {
        ans[i] = -1;
    }
    return MinStep_2_Helper(n, ans);
}

int MinStep_3(int n)
{
    int *ans = new int[n + 1];
    int a = INT_MAX, b = INT_MAX, c = INT_MAX, d = 0;
    ans[0] = 0; // n = 0
    ans[1] = 0; // n = 1
    ans[2] = 1; // n = 2
    ans[3] = 1; // n = 3

    for (int i = 4; i <= n; i++)
    {
        a = ans[i - 1];
        if (i % 2 == 0)
        {
            b = ans[i / 2];
        }
        if (i % 3 == 0)
        {
            c = ans[i / 3];
        }
        d = min(a, min(b, c));
        ans[i] = d + 1;
        a = INT_MAX;
        b = INT_MAX;
        c = INT_MAX;
    }
    return ans[n];
}

int main()
{
    int steps = MinStep_2(11);
    cout << steps;
    return 0;
}