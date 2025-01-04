/*
 * Day: 339 | Date: 2025-01-04
 * Q339: Scramble String
 * Difficulty: Hard
 * Pattern: 2-D DP
 * Section: Dynamic Programming
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1==s2) return true;
        int n=s1.size();
        vector<vector<vector<bool>>> dp(n, vector<vector<bool>>(n, vector<bool>(n)));
        for (int i=0;i<n;++i) for (int j=0;j<n;++j) dp[0][i][j]=(s1[i]==s2[j]);
        for (int len=2; len<=n; ++len)
            for (int i=0;i+len<=n;++i) for (int j=0;j+len<=n;++j){
                for (int k=1;k<len;++k)
                    if ((dp[k-1][i][j]&&dp[len-k-1][i+k][j+k])||(dp[k-1][i][j+len-k]&&dp[len-k-1][i+k][j]))
                        { dp[len-1][i][j]=true; break; }
            }
        return dp[n-1][0][0];
    }
};
