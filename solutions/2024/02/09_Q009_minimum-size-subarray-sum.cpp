/*
 * Day: 9 | Date: 2024-02-09
 * Q009: Minimum Size Subarray Sum
 * Difficulty: Medium
 * Pattern: Two Pointers
 * Section: 1.1 Two Pointers
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = (int)nums.size();
        int l = 0, sum = 0, best = INT_MAX;
        for (int r = 0; r < n; ++r) {
            sum += nums[r];
            while (sum >= target) {
                best = min(best, r - l + 1);
                sum -= nums[l++];
            }
        }
        return best == INT_MAX ? 0 : best;
    }
};
