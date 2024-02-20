/*
 * Day: 20 | Date: 2024-02-20
 * Q020: Number of Subarrays with Product Less Than K
 * Difficulty: Medium
 * Pattern: Sliding Window
 * Section: 1.2 Sliding Window
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;
        long long prod = 1;
        int l = 0, count = 0;
        for (int r = 0; r < (int)nums.size(); ++r) {
            prod *= nums[r];
            while (prod >= k) prod /= nums[l++];
            count += r - l + 1;
        }
        return count;
    }
};
