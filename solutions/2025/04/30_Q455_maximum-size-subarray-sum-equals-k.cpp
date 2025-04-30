/*
 * Day: 455 | Date: 2025-04-30
 * Q455: Maximum Size Subarray Sum Equals k
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
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<long long,int> first{{0, -1}};
        long long sum = 0;
        int best = 0;
        for (int i = 0; i < (int)nums.size(); ++i) {
            sum += nums[i];
            if (first.count(sum - k)) best = max(best, i - first[sum - k]);
            if (!first.count(sum)) first[sum] = i;
        }
        return best;
    }
};
