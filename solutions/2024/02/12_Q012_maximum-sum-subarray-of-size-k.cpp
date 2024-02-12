/*
 * Day: 12 | Date: 2024-02-12
 * Q012: Maximum Sum Subarray of Size K
 * Difficulty: Easy
 * Pattern: Sliding Window
 * Section: 1.2 Sliding Window
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSumSubarrayOfSizeK(vector<int>& nums, int k) {
        int n = (int)nums.size();
        if (n < k || k <= 0) return 0;
        int windowSum = 0, best = INT_MIN;
        for (int i = 0; i < n; ++i) {
            windowSum += nums[i];
            if (i >= k) windowSum -= nums[i - k];
            if (i >= k - 1) best = max(best, windowSum);
        }
        return best;
    }
};
