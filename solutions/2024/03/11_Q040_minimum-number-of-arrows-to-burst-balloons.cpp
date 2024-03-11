/*
 * Day: 40 | Date: 2024-03-11
 * Q040: Minimum Number of Arrows to Burst Balloons
 * Difficulty: Medium
 * Pattern: Kadane's / Greedy
 * Section: 1.4 Kadane's / Greedy
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        int arrows = 0;
        long long lastEnd = LLONG_MIN;
        for (auto& p : points) {
            if ((long long)p[0] > lastEnd) {
                ++arrows;
                lastEnd = p[1];
            }
        }
        return arrows;
    }
};
