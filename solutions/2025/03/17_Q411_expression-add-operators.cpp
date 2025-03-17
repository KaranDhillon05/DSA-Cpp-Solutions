/*
 * Day: 411 | Date: 2025-03-17
 * Q411: Expression Add Operators
 * Difficulty: Hard
 * Pattern: Backtracking
 * Section: 10 Backtracking
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
    void dfs(const string& num, int target, int idx, long long cur, long long prev, string& path, vector<string>& res) {
        if (idx == (int)num.size()) {
            if (cur == target) res.push_back(path);
            return;
        }
        for (int j = idx; j < (int)num.size(); ++j) {
            if (j > idx && num[idx] == '0') break;
            long long val = stoll(num.substr(idx, j - idx + 1));
            if (idx == 0) {
                path = to_string(val);
                dfs(num, target, j + 1, val, val, path, res);
            } else {
                int len = (int)path.size();
                path += "+" + to_string(val);
                dfs(num, target, j + 1, cur + val, val, path, res);
                path.resize(len);
                path += "-" + to_string(val);
                dfs(num, target, j + 1, cur - val, -val, path, res);
                path.resize(len);
                path += "*" + to_string(val);
                dfs(num, target, j + 1, cur - prev + prev * val, prev * val, path, res);
                path.resize(len);
            }
        }
    }
public:
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        string path;
        dfs(num, target, 0, 0, 0, path, res);
        return res;
    }
};
