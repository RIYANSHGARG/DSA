#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007;

long long TotalBST_1(int n)
{
    if (n <= 1)
    {
        return 1;
    }

    long long x = TotalBST_1(n - 1);
    long long y = TotalBST_1(n - 2);

    long long ans = (x * x + 2 * x * y) % mod;

    return ans;
}

int TotalBST_3(int n)
{
    int *ans = new int[n + 1];
    ans[0] = 0;
    ans[1] = 1;
    ans[2] = 3;
    ans[3] = 15;

    for (int i = 4; i <= n; i++)
    {
        ans[i] = pow(2, pow(2, i - 1)) + ans[i - 1] * pow(2, i - 2) - 1;
    }

    return ans[n];
}

int main()
{
    int n = 6;
    int ans = TotalBST_1(n);
    cout << ans;
    return 0;
}