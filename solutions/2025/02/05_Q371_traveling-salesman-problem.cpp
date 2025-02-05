/*
 * Day: 371 | Date: 2025-02-05
 * Q371: Traveling Salesman Problem
 * Difficulty: Hard
 * Pattern: Bitmask DP
 * Section: Dynamic Programming
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int tsp(int n, vector<vector<int>>& dist) {
        const int INF=1e9;
        vector<vector<int>> dp(1<<n, vector<int>(n, INF));
        dp[1][0]=0;
        for (int mask=1; mask<(1<<n); ++mask)
            for (int u=0;u<n;++u) if (mask&(1<<u))
                for (int v=0;v<n;++v) if (!(mask&(1<<v)))
                    dp[mask|(1<<v)][v]=min(dp[mask|(1<<v)][v], dp[mask][u]+dist[u][v]);
        int ans=INF;
        for (int u=1;u<n;++u) ans=min(ans, dp[(1<<n)-1][u]+dist[u][0]);
        return ans;
    }
};
