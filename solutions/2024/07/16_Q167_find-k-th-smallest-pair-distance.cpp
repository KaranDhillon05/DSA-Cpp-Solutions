/*
 * Day: 167 | Date: 2024-07-16
 * Q167: Find K-th Smallest Pair Distance
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
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int lo = 0, hi = nums.back() - nums.front();
        auto cnt = [&](int d) {
            int c = 0, j = 0;
            for (int i = 0; i < (int)nums.size(); ++i) {
                while (j < (int)nums.size() && nums[j] - nums[i] <= d) ++j;
                c += j - i - 1;
            }
            return c;
        };
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (cnt(mid) >= k) hi = mid; else lo = mid + 1;
        }
        return lo;
    }
};
