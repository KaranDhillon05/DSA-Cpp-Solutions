/*
 * Day: 214 | Date: 2024-09-01
 * Q214: Range Sum Query - Mutable
 * Difficulty: Medium
 * Pattern: Segment Tree / BIT
 * Section: Trees
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class NumArray {
    vector<long long> bit;
    vector<int> nums;
    int n;
    void add(int i, int v) { for (; i <= n; i += i & -i) bit[i] += v; }
    long long sum(int i) { long long s = 0; for (; i > 0; i -= i & -i) s += bit[i]; return s; }
public:
    NumArray(vector<int>& nums) : nums(nums), n(nums.size()), bit(n + 1) {
        for (int i = 0; i < n; ++i) add(i + 1, nums[i]);
    }
    void update(int index, int val) {
        add(index + 1, val - nums[index]);
        nums[index] = val;
    }
    int sumRange(int left, int right) { return (int)(sum(right + 1) - sum(left)); }
};
