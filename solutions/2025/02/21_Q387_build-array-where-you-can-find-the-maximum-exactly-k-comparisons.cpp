/*
 * Day: 387 | Date: 2025-02-21
 * Q387: Build Array Where You Can Find The Maximum Exactly K Comparisons
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
    int numOfArrays(int n, int m, int k) {
        const int MOD=1e9+7;
        if (!k||k>n||k>m) return 0;
        vector<vector<vector<long long>>> dp(n+1, vector<vector<long long>>(m+1, vector<long long>(k+1)));
        for (int v=1;v<=m;++v) dp[1][v][1]=1;
        for (int i=2;i<=n;++i)
            for (int mx=1;mx<=m;++mx)
                for (int c=1;c<=k;++c){
                    dp[i][mx][c]=(dp[i][mx][c]+dp[i-1][mx][c]*mx)%MOD;
                    for (int p=1;p<mx;++p)
                        dp[i][mx][c]=(dp[i][mx][c]+dp[i-1][p][c-1])%MOD;
                }
        long long ans=0;
        for (int mx=1;mx<=m;++mx) ans=(ans+dp[n][mx][k])%MOD;
        return (int)ans;
    }
};
