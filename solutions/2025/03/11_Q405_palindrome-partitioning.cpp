/*
 * Day: 405 | Date: 2025-03-11
 * Q405: Palindrome Partitioning
 * Difficulty: Medium
 * Pattern: Backtracking
 * Section: 10 Backtracking
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool isPal(const string& s, int l, int r) {
        while (l < r) if (s[l++] != s[r--]) return false;
        return true;
    }
    void dfs(const string& s, int start, vector<string>& path, vector<vector<string>>& res) {
        if (start == (int)s.size()) { res.push_back(path); return; }
        for (int end = start; end < (int)s.size(); ++end) {
            if (!isPal(s, start, end)) continue;
            path.push_back(s.substr(start, end - start + 1));
            dfs(s, end + 1, path, res);
            path.pop_back();
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        dfs(s, 0, path, res);
        return res;
    }
};
