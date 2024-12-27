/*
 * Day: 331 | Date: 2024-12-27
 * Q331: Count Square Submatrices with All Ones
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
    int countSquares(vector<vector<int>>& matrix) {
        int m=matrix.size(), n=matrix[0].size(), ans=0;
        vector<vector<int>> dp(m, vector<int>(n));
        for (int i=0;i<m;++i) for (int j=0;j<n;++j){
            if (!matrix[i][j]) continue;
            dp[i][j]=1;
            if (i&&j) dp[i][j]=min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]})+1;
            ans+=dp[i][j];
        }
        return ans;
    }
};
