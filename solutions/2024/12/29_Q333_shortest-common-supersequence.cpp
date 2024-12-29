/*
 * Day: 333 | Date: 2024-12-29
 * Q333: Shortest Common Supersequence
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
    string shortestCommonSupersequence(string str1, string str2) {
        int m=str1.size(), n=str2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1));
        for (int i=1;i<=m;++i) for (int j=1;j<=n;++j)
            dp[i][j]=str1[i-1]==str2[j-1]?dp[i-1][j-1]+1:max(dp[i-1][j],dp[i][j-1]);
        string res; int i=m,j=n;
        while (i&&j){
            if (str1[i-1]==str2[j-1]){ res.push_back(str1[i-1]); --i; --j; }
            else if (dp[i-1][j]>=dp[i][j-1]) res.push_back(str1[--i]);
            else res.push_back(str2[--j]);
        }
        while (i) res.push_back(str1[--i]);
        while (j) res.push_back(str2[--j]);
        reverse(res.begin(), res.end());
        return res;
    }
};
