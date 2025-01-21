/*
 * Day: 356 | Date: 2025-01-21
 * Q356: Minimum Cost to Merge Stones
 * Difficulty: Hard
 * Pattern: Interval DP
 * Section: Dynamic Programming
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mergeStones(vector<int>& stones, int k) {
        int n=stones.size();
        if ((n-1)%(k-1)) return -1;
        vector<int> pre(n+1);
        for (int i=0;i<n;++i) pre[i+1]=pre[i]+stones[i];
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(k+1, INT_MAX)));
        for (int i=0;i<n;++i) dp[i][i][1]=0;
        for (int len=2; len<=n; ++len)
            for (int i=0;i+len-1<n;++i){
                int j=i+len-1;
                for (int m=1;m<k;++m)
                    for (int mid=i;mid<j;++mid)
                        if (dp[i][mid][1]!=INT_MAX&&dp[mid+1][j][m]!=INT_MAX)
                            dp[i][j][m+1]=min(dp[i][j][m+1], dp[i][mid][1]+dp[mid+1][j][m]);
                if (dp[i][j][k-1]!=INT_MAX) dp[i][j][k]=dp[i][j][k-1]+pre[j+1]-pre[i];
            }
        return dp[0][n-1][k];
    }
};
