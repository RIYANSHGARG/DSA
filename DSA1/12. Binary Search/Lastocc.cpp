#include <bits/stdc++.h>
using namespace std;

int lastocc(vector<int> v, int x)
{
    bool flag = 0;
    int low = 0, high = v.size() - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (v[mid] == x)
            flag = 1;
        if (v[mid] > x)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return (flag == 1) ? high : -1;
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

    int ans = lastocc(v, x);
    cout << ans;
    return 0;
}