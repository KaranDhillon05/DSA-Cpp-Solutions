/*
 * Day: 31 | Date: 2024-03-02
 * Q031: Maximum Subarray
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
    int maxSubArray(vector<int>& nums) {
        int best = nums[0], cur = nums[0];
        for (int i = 1; i < (int)nums.size(); ++i) {
            cur = max(nums[i], cur + nums[i]);
            best = max(best, cur);
        }
        return best;
    }
};
