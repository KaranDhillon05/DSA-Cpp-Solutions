/*
 * Day: 156 | Date: 2024-07-05
 * Q156: Split Array Largest Sum
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
    int splitArray(vector<int>& nums, int k) {
        auto ok = [&](int mx) {
            int parts = 1, cur = 0;
            for (int x : nums) {
                if (cur + x > mx) { ++parts; cur = 0; }
                cur += x;
            }
            return parts <= k;
        };
        int lo = *max_element(nums.begin(), nums.end());
        int hi = accumulate(nums.begin(), nums.end(), 0);
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (ok(mid)) hi = mid; else lo = mid + 1;
        }
        return lo;
    }
};
