/*
 * Day: 414 | Date: 2025-03-20
 * Q414: Splitting a String Into Descending Consecutive Values
 * Difficulty: Medium
 * Pattern: Backtracking
 * Section: 10 Backtracking
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool dfs(const string& s, int i, long long prev) {
        if (i == (int)s.size()) return true;
        for (int j = i; j < (int)s.size(); ++j) {
            if (j > i && s[i] == '0') break;
            long long val = stoll(s.substr(i, j - i + 1));
            if (prev == -1) {
                if (!dfs(s, j + 1, val)) continue;
                return true;
            }
            if (val == prev - 1 && dfs(s, j + 1, val)) return true;
        }
        return false;
    }
public:
    bool splitString(string s) { return dfs(s, 0, -1); }
};
