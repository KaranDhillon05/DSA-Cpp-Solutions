/*
 * Day: 388 | Date: 2025-02-22
 * Q388: Number of Music Playlists
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
    int numMusicPlaylists(int n, int goal, int k) {
        const long long MOD=1e9+7;
        vector<vector<long long>> dp(goal+1, vector<long long>(n+1));
        dp[0][0]=1;
        for (int i=1;i<=goal;++i)
            for (int j=1;j<=min(i,n);++j){
                dp[i][j]=dp[i-1][j-1]*(n-j+1)%MOD;
                if (j>k) dp[i][j]=(dp[i][j]+dp[i-1][j]*max(0,j-k))%MOD;
            }
        return (int)dp[goal][n];
    }
};
