/*
 * Day: 19 | Date: 2024-02-19
 * Q019: Max Consecutive Ones III
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
    int longestOnes(vector<int>& nums, int k) {
        int l = 0, zeros = 0, best = 0;
        for (int r = 0; r < (int)nums.size(); ++r) {
            if (nums[r] == 0) ++zeros;
            while (zeros > k) {
                if (nums[l] == 0) --zeros;
                ++l;
            }
            best = max(best, r - l + 1);
        }
        return best;
    }
};
