/*
 * Day: 480 | Date: 2025-05-25
 * Q480: Random Pick Index
 * Difficulty: Medium
 * Pattern: Design
 * Section: 13 Design
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> nums;
    mt19937 rng{random_device{}()};
public:
    Solution(vector<int>& nums) : nums(nums) {}
    int pick(int target) {
        vector<int> idx;
        for (int i = 0; i < (int)nums.size(); ++i)
            if (nums[i] == target) idx.push_back(i);
        return idx[rng() % idx.size()];
    }
};
