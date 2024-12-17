/*
 * Day: 321 | Date: 2024-12-17
 * Q321: Integer Break
 * Difficulty: Medium
 * Pattern: 1-D DP
 * Section: Dynamic Programming
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1);
        dp[1]=1;
        for (int i=2;i<=n;++i)
            for (int j=1;j<i;++j) dp[i]=max(dp[i], max(j,dp[j])*max(i-j,dp[i-j]));
        return dp[n];
    }
};
