/*
 * Day: 338 | Date: 2025-01-03
 * Q338: Wildcard Matching
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
        dp[m][n]=true;
        for (int j=n-1;j>=0;--j)
            dp[m][j]=(j+1<n&&p[j+1]=='*'&&dp[m][j+2])||(p[j]=='*'&&dp[m][j+1]);
        for (int i=m-1;i>=0;--i)
            for (int j=n-1;j>=0;--j){
                bool match=(p[j]=='.'||p[j]==s[i]);
                if (j+1<n&&p[j+1]=='*') dp[i][j]=dp[i][j+2]||(match&&dp[i+1][j]);
                else dp[i][j]=match&&dp[i+1][j+1];
            }
        return dp[0][0];
    }
};
