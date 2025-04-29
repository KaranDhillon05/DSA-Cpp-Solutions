/*
 * Day: 454 | Date: 2025-04-29
 * Q454: Contiguous Array
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
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> first{{0, -1}};
        int sum = 0, best = 0;
        for (int i = 0; i < (int)nums.size(); ++i) {
            sum += nums[i] == 1 ? 1 : -1;
            if (first.count(sum)) best = max(best, i - first[sum]);
            else first[sum] = i;
        }
        return best;
    }
};
