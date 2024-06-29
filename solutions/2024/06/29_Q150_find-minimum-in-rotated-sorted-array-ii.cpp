/*
 * Day: 150 | Date: 2024-06-29
 * Q150: Find Minimum in Rotated Sorted Array II
 * Difficulty: Hard
 * Pattern: Classic
 * Section: Binary Search
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int lo = 0, hi = (int)nums.size() - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] > nums[hi]) lo = mid + 1;
            else if (nums[mid] < nums[hi]) hi = mid;
            else --hi;
        }
        return nums[lo];
    }
};
