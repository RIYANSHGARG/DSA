#include <bits/stdc++.h>
using namespace std;

int Recursive(int index1, int index2, string &s1, string &s2)
{
    if (index1 == s1.length() || index2 == s2.length())
        return 0;

    if (s1[index1] == s2[index2])
    {
        return 1 + Recursive(index1 + 1, index2 + 1, s1, s2);
    }
    return max(Recursive(index1 + 1, index2, s1, s2), Recursive(index1, index2 + 1, s1, s2));
}

int memoization(int index1, int index2, string &s1, string &s2, vector<vector<int>> &dp)
{
    // Base Case
    if (index1 == s1.length() || index2 == s2.length())
        return 0;

    // Memoized
    if (dp[index1][index2] != -1)
        return dp[index1][index2];
    // 1 case
    if (s1[index1] == s2[index2])
        return dp[index1][index2] = 1 + memoization(index1 + 1, index2 + 1, s1, s2, dp);
    // 2 case
    return dp[index1][index2] = max(memoization(index1 + 1, index2, s1, s2, dp), memoization(index1, index2 + 1, s1, s2, dp));
}

int extended(int i, int j, string &s1, string &s2, vector<vector<int>> &dp)
{
    if (i == 0 || j == 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (s1[i - 1] == s2[j - 1])
        return dp[i][j] = 1 + extended(i - 1, j - 1, s1, s2, dp);
    return dp[i][j] = max(extended(i - 1, j, s1, s2, dp), extended(i, j - 1, s1, s2, dp));
}

int longestCommonSubsequence(string text1, string text2)
{
    // DP Problem

    // Method 1 : By print all the possible subsequences (Not Working)
    // if(text1.length()>text2.length())   return longestCommonSubsequence(text2,text1);
    // unordered_set<string> s1;
    // for(int i=0;i<(1<<text1.length());i++){
    //     string temp="";
    //     for(int j=0;j<text1.length();j++){
    //         if(i&(1<<j))    temp+=text1[j];
    //     }
    //     s1.insert(temp);
    // }
    // for(int i=(1<<text2.length())-1;i>=0;i--){
    //     string temp="";
    //     for(int j=0;j<text2.length();j++){
    //         if(i&(1<<j))    temp+=text2[j];
    //     }
    //     if(s1.find(temp)!=s1.end()) return temp.length();
    // }
    // return 0;

    // Method 2 : Recursive Approach    (TLE)   TC : O(2^n*2^m)
    // return Recursive(0,0,text1,text2);

    // Method 3 : Memoization
    // TC : O(N*M)
    // SC : O(N*M)+O(N+M)(Stack space As max depth of recursive tree is N+M)
    // vector<vector<int>> dp(text1.length(),vector<int>(text2.length(),-1));
    // return memoization(0,0,text1,text2,dp);

    // Method 3 (EXTENDED)
    // vector<vector<int>> dp(text1.length()+1,vector<int>(text2.length()+1,-1));
    // return extended(text1.length(),text2.length(),text1,text2,dp);

    // Method 4 : Tabulation (eliminating Stack space)
    // int n=text1.size();
    // int m=text2.size();
    // vector<vector<int>> dp(text1.length()+1,vector<int>(text2.length()+1,-1));
    // for(int i=0;i<=n;i++)    dp[i][0]=0;
    // for(int i=0;i<=m;i++)    dp[0][i]=0;
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         if(text1[i-1]==text2[j-1])  dp[i][j]=1+dp[i-1][j-1];
    //         else    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    //     }
    // }
    // return dp[n][m];

    // Method 5 : More Sapce Optimzation (Not Get Properly)
    int n = text1.size();
    int m = text2.size();
    vector<int> prev(m + 1, 0), cur(m + 1, 0);
    for (int i = 0; i <= m; i++)
        prev[i] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (text1[i - 1] == text2[j - 1])
                cur[j] = 1 + prev[j - 1];
            else
                cur[j] = max(prev[j], cur[j - 1]);
        }
        prev = cur;
    }
    return prev[m];
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    int ans = longestCommonSubsequence(s1, s2);
    cout << ans;
    return 0;
}