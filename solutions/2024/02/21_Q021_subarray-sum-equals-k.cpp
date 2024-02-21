/*
 * Day: 21 | Date: 2024-02-21
 * Q021: Subarray Sum Equals K
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
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixCount{{0, 1}};
        int sum = 0, count = 0;
        for (int x : nums) {
            sum += x;
            if (prefixCount.count(sum - k)) count += prefixCount[sum - k];
            ++prefixCount[sum];
        }
        return count;
    }
};
