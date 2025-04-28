/*
 * Day: 453 | Date: 2025-04-28
 * Q453: Subarray Sum Equals K
 * Difficulty: Medium
 * Pattern: Hashing
 * Section: 12 Hashing & Math
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> prefix{{0, 1}};
        int sum = 0, res = 0;
        for (int x : nums) {
            sum += x;
            res += prefix[sum - k];
            ++prefix[sum];
        }
        return res;
    }
};
