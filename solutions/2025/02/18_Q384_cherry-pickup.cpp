/*
 * Day: 384 | Date: 2025-02-18
 * Q384: Cherry Pickup
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
        int n=grid.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n, INT_MIN)));
        dp[0][0][0]=grid[0][0];
        for (int t=1;t<=2*n-2;++t)
            for (int r1=min(t,n-1); r1>=max(0,t-(n-1)); --r1)
                for (int r2=min(t,n-1); r2>=max(0,t-(n-1)); --r2){
                    int c1=t-r1, c2=t-r2;
                    if (grid[r1][c1]==-1||grid[r2][c2]==-1) continue;
                    int gain=grid[r1][c1];
                    if (r1!=r2) gain+=grid[r2][c2];
                    int best=INT_MIN;
                    if (r1) best=max(best, dp[r1-1][r2][c2]);
                    if (c1) best=max(best, dp[r1][r2][c2-1]);
                    if (r1&&r2) best=max(best, dp[r1-1][r2-1][c2]);
                    if (r1&&c2) best=max(best, dp[r1-1][r2][c2-1]);
                    if (best!=INT_MIN) dp[r1][r2][c2]=best+gain;
                }
        return max(0, dp[n-1][n-1][n-1]);
    }
};
