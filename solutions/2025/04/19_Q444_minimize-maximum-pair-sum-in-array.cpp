/*
 * Day: 444 | Date: 2025-04-19
 * Q444: Minimize Maximum Pair Sum in Array
 * Difficulty: Medium
 * Pattern: Greedy
 * Section: 11 Greedy
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = 0;
        for (int i = 0; i < (int)nums.size() / 2; ++i)
            res = max(res, nums[i] + nums[nums.size() - 1 - i]);
        return res;
    }
};
