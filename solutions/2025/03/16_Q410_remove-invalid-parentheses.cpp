/*
 * Day: 410 | Date: 2025-03-16
 * Q410: Remove Invalid Parentheses
 * Difficulty: Hard
 * Pattern: Backtracking
 * Section: 10 Backtracking
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool valid(const string& s) {
        int bal = 0;
        for (char c : s) {
            if (c == '(') ++bal;
            else if (c == ')') { if (--bal < 0) return false; }
        }
        return bal == 0;
    }
    void dfs(const string& s, int i, int rmL, int rmR, string& path, unordered_set<string>& seen, vector<string>& res) {
        if (i == (int)s.size()) {
            if (valid(path) && !seen.count(path)) { seen.insert(path); res.push_back(path); }
            return;
        }
        char c = s[i];
        if ((c == '(' && rmL > 0) || (c == ')' && rmR > 0)) {
            dfs(s, i + 1, rmL - (c == '(' ? 1 : 0), rmR - (c == ')' ? 1 : 0), path, seen, res);
        }
        path.push_back(c);
        dfs(s, i + 1, rmL, rmR, path, seen, res);
        path.pop_back();
    }
public:
    vector<string> removeInvalidParentheses(string s) {
        int rmL = 0, rmR = 0;
        for (char c : s) {
            if (c == '(') ++rmL;
            else if (c == ')') { if (rmL > 0) --rmL; else ++rmR; }
        }
        vector<string> res;
        unordered_set<string> seen;
        string path;
        dfs(s, 0, rmL, rmR, path, seen, res);
        return res;
    }
};
