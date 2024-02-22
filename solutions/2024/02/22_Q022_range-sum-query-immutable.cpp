/*
 * Day: 22 | Date: 2024-02-22
 * Q022: Range Sum Query — Immutable
 * Difficulty: Easy
 * Pattern: Prefix Sum
 * Section: 1.3 Prefix Sum
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class NumArray {
    vector<long long> prefix;
public:
    NumArray(vector<int>& nums) {
        prefix.resize(nums.size() + 1, 0);
        for (int i = 0; i < (int)nums.size(); ++i) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
    }

    int sumRange(int left, int right) {
        return (int)(prefix[right + 1] - prefix[left]);
    }
};
