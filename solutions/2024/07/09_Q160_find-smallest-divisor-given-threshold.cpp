/*
 * Day: 160 | Date: 2024-07-09
 * Q160: Find Smallest Divisor Given Threshold
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
    int smallestDivisor(vector<int>& nums, int threshold) {
        auto ok = [&](int d) {
            long long s = 0;
            for (int x : nums) s += (x + d - 1) / d;
            return s <= threshold;
        };
        int lo = 1, hi = *max_element(nums.begin(), nums.end());
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (ok(mid)) hi = mid; else lo = mid + 1;
        }
        return lo;
    }
};
