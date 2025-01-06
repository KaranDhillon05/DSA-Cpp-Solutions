/*
 * Day: 341 | Date: 2025-01-06
 * Q341: 0/1 Knapsack
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
    int knapsack01(vector<int>& wt, vector<int>& val, int W) {
        int n=wt.size(); vector<int> dp(W+1);
        for (int i=0;i<n;++i)
            for (int w=W; w>=wt[i]; --w)
                dp[w]=max(dp[w], dp[w-wt[i]]+val[i]);
        return dp[W];
    }
};
