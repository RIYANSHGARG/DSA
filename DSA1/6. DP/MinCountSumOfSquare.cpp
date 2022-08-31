#include <bits/stdc++.h>
using namespace std;

int MinCount(int n)
{
    if (n == 0 || n == 1 || n == 2 || n == 3)
    {
        return n;
    }
    int ans = INT_MAX;
    for (int i = 1; i <= int(pow(n, 0.5)); i++)
    {
        ans = min(ans, 1 + MinCount(n - (i * i)));
    }
    return ans;
}

int MinCount_2_helper(int n, int *ans)
{
    if (n == 0 || n == 1 || n == 2 || n == 3)
    {
        return n;
    }

    if (ans[n] != INT_MAX)
    {
        return ans[n];
    }

    for (int i = 1; i <= int(pow(n, 0.5)); i++)
    {
        ans[n] = min(ans[n], 1 + MinCount(n - (i * i)));
    }
    return ans[n];
}

int MinCount_2(int n)
{
    int *ans = new int[n + 1];
    for (int i = 0; i <= n; i++)
    {
        ans[i] = INT_MAX;
    }

    return MinCount_2_helper(n, ans);
}

int MinCount_3(int n)
{
    int point = 0;
    int *ans = new int[n + 1];

    ans[0] = 0;
    ans[1] = 1;
    ans[2] = 2;
    ans[3] = 3;

    for (int i = 4; i <= n; i++)
    {
        if (i == (int(pow(i, 0.5)) * int(pow(i, 0.5))))
        {
            ans[i] = 1;
            point = i;
        }
        ans[i] = 1 + ans[n - point];
    }

    return ans[n];
}

int main()
{
    int n = 10;
    int ans = MinCount_2(n);
    cout << ans;
    return 0;
}