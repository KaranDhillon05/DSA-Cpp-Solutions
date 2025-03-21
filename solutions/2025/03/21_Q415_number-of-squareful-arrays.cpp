/*
 * Day: 415 | Date: 2025-03-21
 * Q415: Number of Squareful Arrays
 * Difficulty: Hard
 * Pattern: Backtracking
 * Section: 10 Backtracking
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool dfs(vector<int>& nums, vector<bool>& used, int prev) {
        if ((int)used.size() == accumulate(used.begin(), used.end(), 0))
            return true;
        for (int i = 0; i < (int)nums.size(); ++i) {
            if (used[i]) continue;
            if (prev != -1 && nums[i] + prev != 0 && nums[i] * prev != 0) continue;
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) continue;
            used[i] = true;
            if (dfs(nums, used, nums[i])) return true;
            used[i] = false;
        }
        return false;
    }
public:
    int numSquarefulPerms(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int count = 0;
        vector<bool> used(nums.size(), false);
        function<void(int)> go = [&](int prev) {
            if ((int)used.size() == accumulate(used.begin(), used.end(), 0)) { ++count; return; }
            for (int i = 0; i < (int)nums.size(); ++i) {
                if (used[i]) continue;
                if (prev != -1 && nums[i] + prev != 0 && nums[i] * prev != 0) continue;
                if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) continue;
                used[i] = true;
                go(nums[i]);
                used[i] = false;
            }
        };
        go(-1);
        return count;
    }
};
