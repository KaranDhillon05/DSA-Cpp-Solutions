/*
 * Day: 350 | Date: 2025-01-15
 * Q350: Count Ways to Build Good Strings
 * Difficulty: Medium
 * Pattern: Knapsack
 * Section: Dynamic Programming
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int goodStrings(int n, int one, int zero, int maxOnes, int maxZeros) {
        const int MOD=1e9+7;
        vector<int> dp(n+1);
        dp[0]=1;
        for (int i=1;i<=n;++i){
            if (i>=one&&maxOnes) dp[i]=(dp[i]+dp[i-one])%MOD;
            if (i>=zero&&maxZeros) dp[i]=(dp[i]+dp[i-zero])%MOD;
        }
        return dp[n];
    }
};
