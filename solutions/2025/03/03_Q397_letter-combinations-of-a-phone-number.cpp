/*
 * Day: 397 | Date: 2025-03-03
 * Q397: Letter Combinations of a Phone Number
 * Difficulty: Medium
 * Pattern: Backtracking
 * Section: 10 Backtracking
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<string> mapping = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void dfs(const string& digits, int i, string& path, vector<string>& res) {
        if (i == (int)digits.size()) { res.push_back(path); return; }
        for (char c : mapping[digits[i] - '0']) {
            path.push_back(c);
            dfs(digits, i + 1, path, res);
            path.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        vector<string> res;
        string path;
        dfs(digits, 0, path, res);
        return res;
    }
};
