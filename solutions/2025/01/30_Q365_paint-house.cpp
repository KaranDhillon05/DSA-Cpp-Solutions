/*
 * Day: 365 | Date: 2025-01-30
 * Q365: Paint House
 * Difficulty: Medium
 * Pattern: State-Machine DP
 * Section: Dynamic Programming
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        if (costs.empty()) return 0;
        int r=costs.size(), c=costs[0].size();
        vector<int> dp=costs[0];
        for (int i=1;i<r;++i){
            vector<int> nd(c);
            for (int j=0;j<c;++j)
                nd[j]=costs[i][j]+min({dp[(j+1)%c], dp[(j+2)%c]});
            dp.swap(nd);
        }
        return *min_element(dp.begin(), dp.end());
    }
};
