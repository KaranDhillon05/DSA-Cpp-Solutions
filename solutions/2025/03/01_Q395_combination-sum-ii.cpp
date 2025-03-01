/*
 * Day: 395 | Date: 2025-03-01
 * Q395: Combination Sum II
 * Difficulty: Medium
 * Pattern: Backtracking
 * Section: 10 Backtracking
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
    void dfs(int i, int target, vector<int>& nums, vector<int>& path, vector<vector<int>>& res) {
        if (target == 0) { res.push_back(path); return; }
        for (int j = i; j < (int)nums.size(); ++j) {
            if (j > i && nums[j] == nums[j - 1]) continue;
            if (nums[j] > target) break;
            path.push_back(nums[j]);
            dfs(j + 1, target - nums[j], nums, path, res);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> path;
        dfs(0, target, candidates, path, res);
        return res;
    }
};
