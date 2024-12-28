/*
 * Day: 332 | Date: 2024-12-28
 * Q332: Longest Common Subsequence
 * Difficulty: Medium
 * Pattern: 2-D DP
 * Section: Dynamic Programming
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.size(), n=text2.size();
        vector<int> dp(n+1);
        for (int i=1;i<=m;++i)
            for (int j=1;j<=n;++j){
                int prev=dp[j];
                if (text1[i-1]==text2[j-1]) dp[j]=dp[j-1]+1;
                else dp[j]=max(dp[j],prev);
            }
        return dp[n];
    }
};
