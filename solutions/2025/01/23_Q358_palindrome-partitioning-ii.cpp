/*
 * Day: 358 | Date: 2025-01-23
 * Q358: Palindrome Partitioning II
 * Difficulty: Hard
 * Pattern: Interval DP
 * Section: Dynamic Programming
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCut(string s) {
        int n=s.size();
        vector<vector<bool>> pal(n, vector<bool>(n,true));
        for (int i=n-1;i>=0;--i)
            for (int j=i+1;j<n;++j)
                pal[i][j]=(s[i]==s[j])&&pal[i+1][j-1];
        vector<int> dp(n); iota(dp.begin(), dp.end(), 0);
        for (int i=0;i<n;++i){
            if (pal[0][i]) dp[i]=0;
            else for (int j=1;j<=i;++j)
                if (pal[j][i]) dp[i]=min(dp[i], dp[j-1]+1);
        }
        return dp[n-1];
    }
};
