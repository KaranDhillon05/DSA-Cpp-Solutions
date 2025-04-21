/*
 * Day: 446 | Date: 2025-04-21
 * Q446: Two Sum
 * Difficulty: Easy
 * Pattern: Hashing
 * Section: 12 Hashing & Math
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> pos;
        for (int i = 0; i < (int)nums.size(); ++i) {
            if (pos.count(target - nums[i])) return {pos[target - nums[i]], i};
            pos[nums[i]] = i;
        }
        return {};
    }
};
