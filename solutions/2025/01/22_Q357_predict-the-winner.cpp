/*
 * Day: 357 | Date: 2025-01-22
 * Q357: Predict the Winner
 * Difficulty: Medium
 * Pattern: Interval DP
 * Section: Dynamic Programming
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i=0;i<n;++i) dp[i][i]=nums[i];
        for (int len=2; len<=n; ++len)
            for (int i=0;i+len-1<n;++i){
                int j=i+len-1;
                dp[i][j]=max(nums[i]-dp[i+1][j], nums[j]-dp[i][j-1]);
            }
        return dp[0][n-1]>=0;
    }
};
