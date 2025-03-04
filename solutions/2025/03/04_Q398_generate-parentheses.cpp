/*
 * Day: 398 | Date: 2025-03-04
 * Q398: Generate Parentheses
 * Difficulty: Medium
 * Pattern: Backtracking
 * Section: 10 Backtracking
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
    void dfs(int open, int close, string& path, vector<string>& res) {
        if ((int)path.size() == 2 * (open)) { res.push_back(path); return; }
        if (open > close) { path.push_back(')'); dfs(open, close + 1, path, res); path.pop_back(); }
        if (open > 0) { path.push_back('('); dfs(open - 1, close, path, res); path.pop_back(); }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string path;
        dfs(n, 0, path, res);
        return res;
    }
};
