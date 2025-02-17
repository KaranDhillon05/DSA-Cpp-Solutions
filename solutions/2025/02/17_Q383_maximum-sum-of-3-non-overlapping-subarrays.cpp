/*
 * Day: 383 | Date: 2025-02-17
 * Q383: Maximum Sum of 3 Non-Overlapping Subarrays
 * Difficulty: Hard
 * Pattern: Tree/Graph DP
 * Section: Dynamic Programming
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> pre(n+1); for (int i=0;i<n;++i) pre[i+1]=pre[i]+nums[i];
        auto sum=[&](int l,int r){ return pre[r+1]-pre[l]; };
        vector<vector<int>> dp(4, vector<int>(n, INT_MIN)), pick(4, vector<int>(n));
        for (int i=k-1;i<n;++i) dp[1][i]=sum(i-k+1,i);
        for (int t=2;t<=3;++t)
            for (int i=t*k-1;i<n;++i){
                dp[t][i]=dp[t][i-1];
                int v=dp[t-1][i-k]+sum(i-k+1,i);
                if (v>dp[t][i]){ dp[t][i]=v; pick[t][i]=i-k+1; }
            }
        return dp[3][n-1];
    }
};
