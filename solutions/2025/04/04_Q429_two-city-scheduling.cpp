/*
 * Day: 429 | Date: 2025-04-04
 * Q429: Two City Scheduling
 * Difficulty: Medium
 * Pattern: Greedy
 * Section: 11 Greedy
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        vector<pair<int,int>> diff;
        for (int i = 0; i < (int)costs.size(); ++i)
            diff.push_back({costs[i][0] - costs[i][1], i});
        sort(diff.begin(), diff.end());
        int res = 0, n = costs.size() / 2;
        for (int i = 0; i < n; ++i) res += costs[diff[i].second][0];
        for (int i = n; i < (int)diff.size(); ++i) res += costs[diff[i].second][1];
        return res;
    }
};
