/*
 * Day: 328 | Date: 2024-12-24
 * Q328: Minimum Path Sum
 * Difficulty: Medium
 * Pattern: 2-D DP
 * Section: Dynamic Programming
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        vector<int> dp(n); dp[0]=grid[0][0];
        for (int j=1;j<n;++j) dp[j]=dp[j-1]+grid[0][j];
        for (int i=1;i<m;++i){
            dp[0]+=grid[i][0];
            for (int j=1;j<n;++j) dp[j]=grid[i][j]+min(dp[j],dp[j-1]);
        }
        return dp[n-1];
    }
};
