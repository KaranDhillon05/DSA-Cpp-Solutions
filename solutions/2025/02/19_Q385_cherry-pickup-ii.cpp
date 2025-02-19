/*
 * Day: 385 | Date: 2025-02-19
 * Q385: Cherry Pickup II
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
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        vector<vector<vector<vector<int>>>> dp(n, vector<vector<vector<int>>>(m, vector<vector<int>>(n, vector<int>(m, INT_MIN))));
        dp[0][0][0][0]=grid[0][0];
        for (int r1=0;r1<n;++r1) for (int c1=0;c1<m;++c1)
            for (int r2=0;r2<n;++r2) for (int c2=0;c2<m;++c2){
                if (grid[r1][c1]==-1||grid[r2][c2]==-1) continue;
                if (!r1&&!c1&&!r2&&!c2) continue;
                int gain=grid[r1][c1];
                if (r1!=r2||c1!=c2) gain+=grid[r2][c2];
                int best=INT_MIN;
                if (r1&&r2) best=max(best, dp[r1-1][c1][r2-1][c2]);
                if (r1&&c2) best=max(best, dp[r1-1][c1][r2][c2-1]);
                if (c1&&r2) best=max(best, dp[r1][c1-1][r2-1][c2]);
                if (c1&&c2) best=max(best, dp[r1][c1-1][r2][c2-1]);
                if (best!=INT_MIN) dp[r1][c1][r2][c2]=best+gain;
            }
        return max(0, dp[n-1][m-1][n-1][m-1]);
    }
};
