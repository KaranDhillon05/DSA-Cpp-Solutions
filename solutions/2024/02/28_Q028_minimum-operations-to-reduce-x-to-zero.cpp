/*
 * Day: 28 | Date: 2024-02-28
 * Q028: Minimum Operations to Reduce X to Zero
 * Difficulty: Medium
 * Pattern: Prefix Sum
 * Section: 1.3 Prefix Sum
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        int target = total - x;
        if (target < 0) return -1;
        if (target == 0) return (int)nums.size();

        int l = 0, sum = 0, best = -1;
        for (int r = 0; r < (int)nums.size(); ++r) {
            sum += nums[r];
            while (sum > target) sum -= nums[l++];
            if (sum == target) best = max(best, r - l + 1);
        }
        return best == -1 ? -1 : (int)nums.size() - best;
    }
};
