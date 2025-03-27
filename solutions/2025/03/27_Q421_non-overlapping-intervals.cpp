/*
 * Day: 421 | Date: 2025-03-27
 * Q421: Non-overlapping Intervals
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
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) {
            return a[1] < b[1];
        });
        int end = intervals[0][1], removed = 0;
        for (int i = 1; i < (int)intervals.size(); ++i) {
            if (intervals[i][0] < end) ++removed;
            else end = intervals[i][1];
        }
        return removed;
    }
};
