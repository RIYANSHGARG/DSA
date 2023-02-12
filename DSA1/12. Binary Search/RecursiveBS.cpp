#include <bits/stdc++.h>
using namespace std;

int findelerecur(int low, int high, vector<int> v, int x)
{
    if (high < low)
        return -1;
    int mid = (low + high) / 2;
    if (v[mid] == x)
        return mid;
    if (v[mid] < x)
        return findelerecur(mid + 1, high, v, x);
    return findelerecur(low, mid - 1, v, x);
}
signed main()
{
#ifdef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // DEBUG
    int n, x;
    cin >> n >> x;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int element;
        cin >> element;
        v.push_back(element);
    }

    int ans = findelerecur(0, n - 1, v, x);
    cout << ans;
    return 0;
}