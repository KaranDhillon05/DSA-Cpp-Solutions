/*
 * Day: 327 | Date: 2024-12-23
 * Q327: Unique Paths II
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
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size(), n=obstacleGrid[0].size();
        if (obstacleGrid[0][0]) return 0;
        vector<int> dp(n); dp[0]=1;
        for (int i=0;i<m;++i)
            for (int j=0;j<n;++j){
                if (obstacleGrid[i][j]) dp[j]=0;
                else if (j>0) dp[j]+=dp[j-1];
            }
        return dp[n-1];
    }
};
