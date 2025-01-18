/*
 * Day: 353 | Date: 2025-01-18
 * Q353: Strange Printer
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
    int strangePrinter(string s) {
        int n=s.size(); vector<vector<int>> dp(n, vector<int>(n));
        for (int i=0;i<n;++i) dp[i][i]=1;
        for (int len=2; len<=n; ++len)
            for (int i=0;i+len-1<n;++i){
                int j=i+len-1; dp[i][j]=len;
                if (s[i]==s[j]) dp[i][j]=max(0,dp[i][j-1]-1);
                else for (int k=i;k<j;++k) dp[i][j]=min(dp[i][j], dp[i][k]+dp[k+1][j]);
            }
        return dp[0][n-1];
    }
};
