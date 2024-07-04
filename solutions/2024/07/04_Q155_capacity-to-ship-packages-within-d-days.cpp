/*
 * Day: 155 | Date: 2024-07-04
 * Q155: Capacity To Ship Packages Within D Days
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
    int shipWithinDays(vector<int>& weights, int days) {
        auto ok = [&](int cap) {
            int d = 1, cur = 0;
            for (int w : weights) {
                if (cur + w > cap) { ++d; cur = 0; }
                cur += w;
            }
            return d <= days;
        };
        int lo = *max_element(weights.begin(), weights.end());
        int hi = accumulate(weights.begin(), weights.end(), 0);
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (ok(mid)) hi = mid; else lo = mid + 1;
        }
        return lo;
    }
};
