/*
 * Day: 342 | Date: 2025-01-07
 * Q342: Unbounded Knapsack
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
    int unboundedKnapsack(vector<int>& wt, vector<int>& val, int W) {
        vector<int> dp(W+1);
        for (int w=1; w<=W; ++w)
            for (int i=0;i<(int)wt.size();++i)
                if (wt[i]<=w) dp[w]=max(dp[w], dp[w-wt[i]]+val[i]);
        return dp[W];
    }
};
