/*
 * Day: 343 | Date: 2025-01-08
 * Q343: Partition Equal Subset Sum
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
    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(), nums.end(), 0);
        if (sum%2) return false;
        int target=sum/2; vector<bool> dp(target+1); dp[0]=true;
        for (int x:nums) for (int t=target; t>=x; --t) dp[t]=dp[t]||dp[t-x];
        return dp[target];
    }
};
