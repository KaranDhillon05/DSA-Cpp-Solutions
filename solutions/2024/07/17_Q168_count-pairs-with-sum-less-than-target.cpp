/*
 * Day: 168 | Date: 2024-07-17
 * Q168: Count Pairs with Sum Less Than Target
 * Difficulty: Medium
 * Pattern: Parametric
 * Section: Binary Search
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans = 0, n = nums.size();
        for (int i = 0; i < n; ++i) {
            int lo = i + 1, hi = n - 1;
            while (lo <= hi) {
                int mid = lo + (hi - lo) / 2;
                if (nums[i] + nums[mid] < target) lo = mid + 1; else hi = mid - 1;
            }
            ans += lo - i - 1;
        }
        return ans;
    }
};
