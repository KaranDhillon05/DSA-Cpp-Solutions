/*
 * Day: 349 | Date: 2025-01-14
 * Q349: Combination Sum IV
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
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned> dp(target+1); dp[0]=1;
        for (int t=1;t<=target;++t)
            for (int x:nums) if (t>=x) dp[t]+=dp[t-x];
        return (int)dp[target];
    }
};
