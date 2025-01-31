/*
 * Day: 366 | Date: 2025-01-31
 * Q366: Paint House II
 * Difficulty: Hard
 * Pattern: State-Machine DP
 * Section: Dynamic Programming
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        if (costs.empty()) return 0;
        int r=costs.size(), k=costs[0].size();
        vector<int> dp=costs[0];
        for (int i=1;i<r;++i){
            vector<int> nd(k, INT_MAX);
            for (int j=0;j<k;++j)
                for (int p=0;p<k;++p)
                    if (p!=j) nd[j]=min(nd[j], dp[p]+costs[i][j]);
            dp.swap(nd);
        }
        return *min_element(dp.begin(), dp.end());
    }
};
