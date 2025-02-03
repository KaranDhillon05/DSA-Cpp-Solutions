/*
 * Day: 369 | Date: 2025-02-03
 * Q369: Coin Path
 * Difficulty: Hard
 * Pattern: State-Machine DP
 * Section: Dynamic Programming
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumCoins(vector<int>& coins, int maxJump) {
        int n=coins.size(); const int INF=1e9;
        vector<int> dp(n, INF); dp[0]=0;
        for (int i=0;i<n;++i) if (dp[i]!=INF)
            for (int j=i+1;j<=min(n-1,i+maxJump);++j)
                dp[j]=min(dp[j], dp[i]+coins[j]);
        return dp[n-1]>=INF?-1:dp[n-1];
    }
};
