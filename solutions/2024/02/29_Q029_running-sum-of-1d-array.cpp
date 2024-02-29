/*
 * Day: 29 | Date: 2024-02-29
 * Q029: Running Sum of 1D Array
 * Difficulty: Easy
 * Pattern: Prefix Sum
 * Section: 1.3 Prefix Sum
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        for (int i = 1; i < (int)nums.size(); ++i) {
            nums[i] += nums[i - 1];
        }
        return nums;
    }
};
