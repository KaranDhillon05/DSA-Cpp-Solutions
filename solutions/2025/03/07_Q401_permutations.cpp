/*
 * Day: 401 | Date: 2025-03-07
 * Q401: Permutations
 * Difficulty: Medium
 * Pattern: Backtracking
 * Section: 10 Backtracking
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
    void dfs(vector<int>& nums, vector<int>& path, vector<vector<int>>& res) {
        if (path.size() == nums.size()) { res.push_back(path); return; }
        for (int i = 0; i < (int)nums.size(); ++i) {
            if (nums[i] == INT_MIN) continue;
            int pick = nums[i];
            nums[i] = INT_MIN;
            path.push_back(pick);
            dfs(nums, path, res);
            path.pop_back();
            nums[i] = pick;
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        dfs(nums, path, res);
        return res;
    }
};
