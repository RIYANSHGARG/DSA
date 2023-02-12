#include <bits/stdc++.h>
using namespace std;

int maxJump(vector<int> &stones, int n)
{
    if (n == 0)
        return 0;
    int left = maxJump(stones, n - 1) + (stones[n] - stones[n - 1]);
    int right = INT_MAX;
    if (n > 1)
        right = maxJump(stones, n - 2) + (stones[n] - stones[n - 2]);
    return min(left, right);
}

int maxJump_2Helper(vector<int> &v, int n, vector<int> &dp)
{

    if (n == 0)
        return 0;
    if (dp[n] != -1)
        return dp[n];
    int left = maxJump_2Helper(v, n - 1, dp) + (v[n] - v[n - 1]);
    int right = INT_MAX;
    if (n > 1)
        right = maxJump_2Helper(v, n - 2, dp) + (v[n] - v[n - 2]);
    return dp[n] = min(left, right);
}

int maxJump_2(vector<int> &v, int n)
{
    vector<int> dp(n + 1, -1);
    return maxJump_2Helper(v, n, dp);
}

int maxJump_3(vector<int> &v, int n)
{
    vector<int> dp(n, 0);
    for (int i = 1; i <= n; i++)
    {
        int ff = dp[i - 1] + abs(v[i] - v[i - 1]);
        int ss = INT_MAX;
        if (i > 1)
            ss = dp[i - 2] + abs(v[i] - v[i - 2]);
        dp[i] = min(ff, ss);
    }
    for (auto i : dp)
    {
        cout << i << " ";
    }
    cout << endl;
    return dp[n];
}

int maxJump_4(vector<int> &v, int n)
{
    int prev1 = 0, prev2 = 0;
    for (int i = 1; i <= n; i++)
    {
        int ff = prev1 + abs(v[i] - v[i - 1]);
        int ss = INT_MAX;
        if (i > 1)
            ss = prev2 + abs(v[i] - v[i - 2]);
        int cur = min(ff, ss);
        prev2 = prev1;
        prev1 = cur;
    }
    return prev1;
}

int main()
{
    vector<int> v = {0, 2, 5, 6, 7};
    int ans = maxJump_4(v, v.size() - 1);
    cout << ans;
    return 0;
}