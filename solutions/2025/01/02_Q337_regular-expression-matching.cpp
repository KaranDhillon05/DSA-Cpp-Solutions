/*
 * Day: 337 | Date: 2025-01-02
 * Q337: Regular Expression Matching
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
    bool isMatch(string s, string p) {
        int m=s.size(), n=p.size();
        vector<vector<bool>> dp(m+1, vector<bool>(n+1));
        dp[0][0]=true;
        for (int j=2;j<=n;++j) if(p[j-1]=='*') dp[0][j]=dp[0][j-2];
        for (int i=1;i<=m;++i) for (int j=1;j<=n;++j){
            if (p[j-1]=='*'){
                dp[i][j]=dp[i][j-2];
                if (p[j-2]=='.'||p[j-2]==s[i-1]) dp[i][j]=dp[i][j]||dp[i-1][j];
            } else if (p[j-1]=='.'||p[j-1]==s[i-1]) dp[i][j]=dp[i-1][j-1];
        }
        return dp[m][n];
    }
};
