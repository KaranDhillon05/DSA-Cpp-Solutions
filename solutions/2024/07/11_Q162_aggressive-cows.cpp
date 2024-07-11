/*
 * Day: 162 | Date: 2024-07-11
 * Q162: Aggressive Cows
 * Difficulty: Hard
 * Pattern: Parametric
 * Section: Binary Search
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int aggressiveCows(vector<int>& stalls, int cows) {
        sort(stalls.begin(), stalls.end());
        auto ok = [&](int dist) {
            int placed = 1, prev = stalls[0];
            for (int i = 1; i < (int)stalls.size(); ++i)
                if (stalls[i] - prev >= dist) { ++placed; prev = stalls[i]; }
            return placed >= cows;
        };
        int lo = 1, hi = stalls.back() - stalls.front();
        while (lo < hi) {
            int mid = lo + (hi - lo + 1) / 2;
            if (ok(mid)) lo = mid; else hi = mid - 1;
        }
        return lo;
    }
};
