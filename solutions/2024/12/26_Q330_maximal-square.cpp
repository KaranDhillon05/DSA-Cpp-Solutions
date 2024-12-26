/*
 * Day: 330 | Date: 2024-12-26
 * Q330: Maximal Square
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
    int maximalSquare(vector<vector<char>>& matrix) {
        int m=matrix.size(), n=matrix[0].size(), best=0;
        vector<int> dp(n+1);
        for (int i=1;i<=m;++i)
            for (int j=1;j<=n;++j){
                if (matrix[i-1][j-1]=='1'){
                    dp[j]=min({dp[j],dp[j-1],dp[j-1]})+1;
                    best=max(best,dp[j]);
                } else dp[j]=0;
            }
        return best*best;
    }
};
