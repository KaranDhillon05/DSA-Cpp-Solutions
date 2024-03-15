/*
 * Day: 44 | Date: 2024-03-15
 * Q044: Non-overlapping Intervals
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
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        int kept = 0;
        int lastEnd = INT_MIN;
        for (auto& iv : intervals) {
            if (iv[0] >= lastEnd) {
                ++kept;
                lastEnd = iv[1];
            }
        }
        return (int)intervals.size() - kept;
    }
};
