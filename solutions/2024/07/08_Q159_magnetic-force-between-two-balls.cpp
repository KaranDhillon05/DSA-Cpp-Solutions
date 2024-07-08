/*
 * Day: 159 | Date: 2024-07-08
 * Q159: Magnetic Force Between Two Balls
 * Difficulty: Medium
 * Pattern: Parametric
 * Section: Binary Search
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        auto ok = [&](int dist) {
            int placed = 1, prev = position[0];
            for (int i = 1; i < (int)position.size(); ++i)
                if (position[i] - prev >= dist) { ++placed; prev = position[i]; }
            return placed >= m;
        };
        int lo = 1, hi = position.back() - position.front();
        while (lo < hi) {
            int mid = lo + (hi - lo + 1) / 2;
            if (ok(mid)) lo = mid; else hi = mid - 1;
        }
        return lo;
    }
};
