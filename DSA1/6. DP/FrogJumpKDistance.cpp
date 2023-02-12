#include <bits/stdc++.h>
using namespace std;

int MaxJump(vector<int> &v, int n, int k, int ans)
{
    if (n == 0)
        return 0;

    for (int i = 1; i <= k; i++)
    {
        if (n - i >= 0)
            ans = min(MaxJump(v, n - i, k, ans) + abs(v[n] - v[n - i]), ans);
    }
    return ans;
}

int main()
{
    int k = 1;
    vector<int> v = {0, 2, 5, 6, 7};
    int ans = MaxJump(v, v.size(), k, INT_MAX);
    cout << ans;
    return 0;
}

// not working