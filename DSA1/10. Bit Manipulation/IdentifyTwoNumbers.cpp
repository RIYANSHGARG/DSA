// Approach 1 : traversing and cheching it it exists twice of not.   O(N^2)
// Approach 2 : putting all the values to map and cheching if any value is 1 or not then print first one   O(NlogN) and also space complexity O(n)
// Approach 3 : Bit Manipulation as done below   O(N) and space complexity O(1).

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int XOR = 0, ans1 = 0, ans2 = 0;
    int a[10] = {1, 1, 2, 2, 3, 4, 4, 5, 6, 6};
    vector<int> b, c;

    // Finding XOR
    for (int i = 0; i < 10; i++)
    {
        XOR = XOR ^ a[i];
    }

    // Finding right most set bit
    // ffs() function also gives the least significant set bit i.e. rightmost set bit
    int counter = 0;
    while (XOR)
    {
        if (XOR & 1)
        {
            break;
        }
        counter++;
        XOR = XOR >> 1;
    }

    // dividing 1 array to two different arrays on the basis of that set bit
    // for (int i = 0; i < 10; i++)
    // {
    //     if (a[i] & (1 << counter))
    //     {
    //         b.push_back(a[i]);
    //     }
    //     else
    //     {
    //         c.push_back(a[i]);
    //     }
    // }

    // // XORing the two arrays will give two integers.
    // for (int i = 0; i < b.size(); i++)
    // {
    //     ans1 ^= b[i];
    // }
    // for (int i = 0; i < c.size(); i++)
    // {
    //     ans2 ^= c[i];
    // }

    // Cut Shorting it and making space complexity 1

    for (int i = 0; i < 10; i++)
    {
        if (a[i] & (1 << counter))
        {
            ans1 ^= a[i];
            continue;
        }
        ans2 ^= a[i];
    }

    cout << ans1 << ans2;

    return 0;
}