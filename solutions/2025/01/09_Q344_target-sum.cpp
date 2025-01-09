/*
 * Day: 344 | Date: 2025-01-09
 * Q344: Target Sum
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
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=accumulate(nums.begin(), nums.end(), 0);
        if ((target+sum)%2||abs(target)>sum) return 0;
        int t=(target+sum)/2; vector<int> dp(t+1); dp[0]=1;
        for (int x:nums) for (int i=t;i>=x;--i) dp[i]+=dp[i-x];
        return dp[t];
    }
};
