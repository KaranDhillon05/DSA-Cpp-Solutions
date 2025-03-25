/*
 * Day: 419 | Date: 2025-03-25
 * Q419: Factor Combinations
 * Difficulty: Medium
 * Pattern: Backtracking
 * Section: 10 Backtracking
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
    void dfs(int start, int n, vector<int>& path, vector<vector<int>>& res) {
        if (n == 1) {
            if (path.size() > 1) res.push_back(path);
            return;
        }
        for (int i = max(2, start); i <= n; ++i) {
            if (n % i == 0) {
                path.push_back(i);
                dfs(i, n / i, path, res);
                path.pop_back();
            }
        }
    }
public:
    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> res;
        vector<int> path;
        dfs(2, n, path, res);
        return res;
    }
};
