/*
 * Day: 340 | Date: 2025-01-05
 * Q340: Burst Balloons
 * Difficulty: Hard
 * Pattern: 2-D DP
 * Section: Dynamic Programming
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1); nums.push_back(1);
        int n=nums.size();
        vector<vector<int>> dp(n, vector<int>(n));
        for (int len=3; len<=n; ++len)
            for (int l=0; l+len-1<n; ++l){
                int r=l+len-1;
                for (int k=l+1;k<r;++k)
                    dp[l][r]=max(dp[l][r], dp[l][k]+dp[k][r]+nums[l]*nums[k]*nums[r]);
            }
        return dp[0][n-1];
    }
};
