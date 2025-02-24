/*
 * Day: 390 | Date: 2025-02-24
 * Q390: Minimum Cost to Cut a Stick
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
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0); cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        int m=cuts.size();
        vector<vector<int>> dp(m, vector<int>(m));
        for (int len=2; len<m; ++len)
            for (int i=0;i+len<m;++i){
                int j=i+len;
                dp[i][j]=INT_MAX;
                for (int k=i+1;k<j;++k)
                    dp[i][j]=min(dp[i][j], dp[i][k]+dp[k][j]+cuts[j]-cuts[i]);
            }
        return dp[0][m-1];
    }
};
