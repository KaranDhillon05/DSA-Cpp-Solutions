/*
 * Day: 347 | Date: 2025-01-12
 * Q347: Profitable Schemes
 * Difficulty: Hard
 * Pattern: Knapsack
 * Section: Dynamic Programming
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        const int MOD=1e9+7;
        vector<vector<int>> dp(n+1, vector<int>(minProfit+1));
        dp[0][0]=1;
        for (int k=0;k<(int)group.size();++k)
            for (int i=n;i>=group[k];--i)
                for (int p=minProfit;p>=0;--p){
                    int np=min(minProfit, p+profit[k]);
                    dp[i][np]=(dp[i][np]+dp[i-group[k]][p])%MOD;
                }
        return dp[n][minProfit];
    }
};
