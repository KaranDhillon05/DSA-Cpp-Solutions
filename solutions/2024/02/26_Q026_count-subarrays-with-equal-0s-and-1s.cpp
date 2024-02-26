/*
 * Day: 26 | Date: 2024-02-26
 * Q026: Count Subarrays with Equal 0s and 1s
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
    int countEqual01Subarrays(vector<int>& nums) {
        unordered_map<int, int> diffCount{{0, 1}};
        int diff = 0, count = 0;
        for (int x : nums) {
            diff += x == 1 ? 1 : -1;
            if (diffCount.count(diff)) count += diffCount[diff];
            ++diffCount[diff];
        }
        return count;
    }
};
