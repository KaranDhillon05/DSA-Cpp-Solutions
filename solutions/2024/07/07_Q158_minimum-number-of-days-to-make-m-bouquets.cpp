/*
 * Day: 158 | Date: 2024-07-07
 * Q158: Minimum Number of Days to Make m Bouquets
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
    int minDays(vector<int>& bloomDay, int m, int k) {
        if ((long long)m * k > bloomDay.size()) return -1;
        auto ok = [&](int day) {
            int bouquets = 0, flowers = 0;
            for (int d : bloomDay) {
                if (d <= day) { if (++flowers == k) { ++bouquets; flowers = 0; } }
                else flowers = 0;
            }
            return bouquets >= m;
        };
        int lo = 1, hi = *max_element(bloomDay.begin(), bloomDay.end());
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (ok(mid)) hi = mid; else lo = mid + 1;
        }
        return lo;
    }
};
