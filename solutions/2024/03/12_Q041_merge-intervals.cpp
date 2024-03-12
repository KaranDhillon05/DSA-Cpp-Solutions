/*
 * Day: 41 | Date: 2024-03-12
 * Q041: Merge Intervals
 * Difficulty: Medium
 * Pattern: Sorting & Searching
 * Section: 1.5 Sorting & Searching
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        for (auto& iv : intervals) {
            if (res.empty() || iv[0] > res.back()[1]) {
                res.push_back(iv);
            } else {
                res.back()[1] = max(res.back()[1], iv[1]);
            }
        }
        return res;
    }
};
