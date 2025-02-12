/*
 * Day: 378 | Date: 2025-02-12
 * Q378: Count Ways to Distribute Candies
 * Difficulty: Hard
 * Pattern: Bitmask DP
 * Section: Dynamic Programming
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int waysToDistribute(int n, int k) {
        const int MOD=1e9+7;
        vector<vector<long long>> dp(n+1, vector<long long>(k+1));
        dp[0][0]=1;
        for (int i=1;i<=n;++i)
            for (int j=1;j<=min(i,k);++j)
                dp[i][j]=(dp[i-1][j-1]+j*dp[i-1][j])%MOD;
        return (int)dp[n][k];
    }
};
