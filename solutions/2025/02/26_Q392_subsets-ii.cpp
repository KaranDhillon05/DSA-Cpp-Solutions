/*
 * Day: 392 | Date: 2025-02-26
 * Q392: Subsets II
 * Difficulty: Medium
 * Pattern: Backtracking
 * Section: 10 Backtracking
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
    void dfs(int i, vector<int>& nums, vector<int>& path, vector<vector<int>>& res) {
        res.push_back(path);
        for (int j = i; j < (int)nums.size(); ++j) {
            if (j > i && nums[j] == nums[j - 1]) continue;
            path.push_back(nums[j]);
            dfs(j + 1, nums, path, res);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> path;
        dfs(0, nums, path, res);
        return res;
    }
};
