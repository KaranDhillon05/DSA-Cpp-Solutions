/*
 * Day: 23 | Date: 2024-02-23
 * Q023: Continuous Subarray Sum
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
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> modIndex{{0, -1}};
        int sum = 0;
        for (int i = 0; i < (int)nums.size(); ++i) {
            sum += nums[i];
            int rem = k == 0 ? sum : sum % k;
            if (modIndex.count(rem)) {
                if (i - modIndex[rem] >= 2) return true;
            } else {
                modIndex[rem] = i;
            }
        }
        return false;
    }
};
