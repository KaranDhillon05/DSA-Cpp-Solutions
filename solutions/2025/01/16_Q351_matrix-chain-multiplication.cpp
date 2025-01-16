/*
 * Day: 351 | Date: 2025-01-16
 * Q351: Matrix Chain Multiplication
 * Difficulty: Hard
 * Pattern: Interval DP
 * Section: Dynamic Programming
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int matrixChainOrder(vector<int>& arr) {
        int n=arr.size()-1;
        vector<vector<int>> dp(n, vector<int>(n));
        for (int len=2; len<=n; ++len)
            for (int i=0;i+len-1<n;++i){
                int j=i+len-1; dp[i][j]=INT_MAX;
                for (int k=i;k<j;++k)
                    dp[i][j]=min(dp[i][j], dp[i][k]+dp[k+1][j]+arr[i]*arr[k+1]*arr[j+1]);
            }
        return dp[0][n-1];
    }
};
