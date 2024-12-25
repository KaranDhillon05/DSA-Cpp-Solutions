/*
 * Day: 329 | Date: 2024-12-25
 * Q329: Dungeon Game
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
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m=dungeon.size(), n=dungeon[0].size();
        vector<vector<int>> dp(m, vector<int>(n,INT_MAX));
        dp[m-1][n-1]=max(1,1-dungeon[m-1][n-1]);
        for (int i=m-2;i>=0;--i) dp[i][n-1]=max(1,dp[i+1][n-1]-dungeon[i][n-1]);
        for (int j=n-2;j>=0;--j) dp[m-1][j]=max(1,dp[m-1][j+1]-dungeon[m-1][j]);
        for (int i=m-2;i>=0;--i)
            for (int j=n-2;j>=0;--j)
                dp[i][j]=max(1,min(dp[i+1][j],dp[i][j+1])-dungeon[i][j]);
        return dp[0][0];
    }
};
