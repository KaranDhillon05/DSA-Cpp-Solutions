/*
 * Day: 222 | Date: 2024-09-09
 * Q222: Rectangle Area II
 * Difficulty: Hard
 * Pattern: Segment Tree / BIT
 * Section: Trees
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        const int MOD = 1'000'000'007;
        vector<int> xs;
        for (auto& r : rectangles) { xs.push_back(r[0]); xs.push_back(r[2]); }
        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());
        long long area = 0;
        int prevX = xs[0];
        for (int x : xs) {
            if (x == prevX) continue;
            vector<pair<int,int>> intervals;
            for (auto& r : rectangles)
                if (r[0] <= prevX && r[2] >= x)
                    intervals.push_back({r[1], r[3]});
            sort(intervals.begin(), intervals.end());
            long long covered = 0;
            int curL = -1, curR = -1;
            for (auto& [l, r] : intervals) {
                if (curR < l) { covered += curR - curL; curL = l; curR = r; }
                else curR = max(curR, r);
            }
            covered += max(0, curR - curL);
            area = (area + covered * (x - prevX)) % MOD;
            prevX = x;
        }
        return (int)area;
    }
};
