/*
 * Day: 424 | Date: 2025-03-30
 * Q424: Fractional Knapsack
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
    double fractionalKnapsack(int W, vector<int>& val, vector<int>& wt) {
        int n = val.size();
        vector<pair<double,int>> items;
        for (int i = 0; i < n; ++i) items.push_back({(double)val[i] / wt[i], i});
        sort(items.begin(), items.end(), greater<pair<double,int>>());
        double res = 0;
        for (auto& [ratio, i] : items) {
            if (W >= wt[i]) { res += val[i]; W -= wt[i]; }
            else { res += ratio * W; break; }
        }
        return res;
    }
};
