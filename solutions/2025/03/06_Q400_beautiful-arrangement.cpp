/*
 * Day: 400 | Date: 2025-03-06
 * Q400: Beautiful Arrangement
 * Difficulty: Medium
 * Pattern: Backtracking
 * Section: 10 Backtracking
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
    int count = 0;
    void dfs(int pos, int n, vector<int>& nums, vector<bool>& used) {
        if (pos == n) { ++count; return; }
        for (int i = 0; i < n; ++i) {
            if (used[i]) continue;
            if (nums[i] % (pos + 1) != 0 && (pos + 1) % nums[i] != 0) continue;
            used[i] = true;
            dfs(pos + 1, n, nums, used);
            used[i] = false;
        }
    }
public:
    int countArrangement(int n) {
        vector<int> nums(n);
        iota(nums.begin(), nums.end(), 1);
        vector<bool> used(n, false);
        dfs(0, n, nums, used);
        return count;
    }
};
