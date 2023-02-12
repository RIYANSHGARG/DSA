#include <iostream>
using namespace std;

string longestPalindrome(string s)
{
    // Method 2 :
    if (s.length() == 1)
        return s;

    int n = s.length();
    int st = 0, e = 0, max_length = 1;
    // odd palidrome
    for (int i = 0; i < n; i++)
    {
        int l = i, r = i;
        while (l >= 0 && r < n)
        {
            int l = r = s[i];
            if (s[l] == s[r])
            {
                l--;
                r++;
            }
            break;
        }
        if (max_length < r - l + 1)
        {
            max_length = r - l + 1;
            st = l + 1;
            e = r - 1;
        }
    }
    // even palindrome
    for (int i = 0; i < n; i++)
    {
        int l = i, r = i + 1;
        while (l >= 0 && r < n)
        {
            if (s[l] == s[r])
            {
                l--;
                r++;
            }
            break;
        }
        if (max_length < r - l + 1)
        {
            max_length = r - l + 1;
            s = l + 1;
            e = r - 1;
        }
    }
    return s.substr(st, max_length);
}

int main()
{
    string s = "abbad";
    string ans = longestPalindrome(s);
    cout << ans;
    return 0;
}