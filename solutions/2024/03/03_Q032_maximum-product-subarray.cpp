/*
 * Day: 32 | Date: 2024-03-03
 * Q032: Maximum Product Subarray
 * Difficulty: Medium
 * Pattern: Kadane's / Greedy
 * Section: 1.4 Kadane's / Greedy
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int best = nums[0], curMax = nums[0], curMin = nums[0];
        for (int i = 1; i < (int)nums.size(); ++i) {
            if (nums[i] < 0) swap(curMax, curMin);
            curMax = max(nums[i], curMax * nums[i]);
            curMin = min(nums[i], curMin * nums[i]);
            best = max(best, curMax);
        }
        return best;
    }
};
