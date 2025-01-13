/*
 * Day: 348 | Date: 2025-01-13
 * Q348: Number of Dice Rolls With Target Sum
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
    int numRollsToTarget(int n, int k, int target) {
        const int MOD=1e9+7;
        vector<int> dp(target+1); dp[0]=1;
        for (int i=0;i<n;++i){
            vector<int> nd(target+1);
            for (int t=1;t<=target;++t)
                for (int f=1;f<=k;++f) if (t>=f) nd[t]=(nd[t]+dp[t-f])%MOD;
            dp.swap(nd);
        }
        return dp[target];
    }
};
