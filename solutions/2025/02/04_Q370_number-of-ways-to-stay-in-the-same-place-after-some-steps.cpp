/*
 * Day: 370 | Date: 2025-02-04
 * Q370: Number of Ways to Stay in the Same Place After Some Steps
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
    int numPaths(int steps, int arrLen) {
        const int MOD=1e9+7;
        int posMax=min(arrLen-1, steps/2);
        vector<vector<int>> dp(steps+1, vector<int>(posMax+1));
        dp[0][0]=1;
        for (int s=1;s<=steps;++s)
            for (int p=0;p<=posMax;++p){
                dp[s][p]=dp[s-1][p];
                if (p) dp[s][p]=(dp[s][p]+dp[s-1][p-1])%MOD;
                if (p<posMax) dp[s][p]=(dp[s][p]+dp[s-1][p+1])%MOD;
            }
        return dp[steps][0];
    }
};
