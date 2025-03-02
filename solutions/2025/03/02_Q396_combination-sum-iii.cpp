/*
 * Day: 396 | Date: 2025-03-02
 * Q396: Combination Sum III
 * Difficulty: Medium
 * Pattern: Backtracking
 * Section: 10 Backtracking
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
    void dfs(int start, int k, int n, int used, vector<int>& path, vector<vector<int>>& res) {
        if ((int)path.size() == k) {
            if (used == n) res.push_back(path);
            return;
        }
        for (int d = start; d <= 9; ++d) {
            if (used + d > n) break;
            path.push_back(d);
            dfs(d + 1, k, n, used + d, path, res);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> path;
        dfs(1, k, n, 0, path, res);
        return res;
    }
};
