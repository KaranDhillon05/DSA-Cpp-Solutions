/*
 * Day: 412 | Date: 2025-03-18
 * Q412: Restore IP Addresses
 * Difficulty: Medium
 * Pattern: Backtracking
 * Section: 10 Backtracking
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool valid(const string& s) {
        if (s.empty() || (s.size() > 1 && s[0] == '0')) return false;
        int val = stoi(s);
        return val >= 0 && val <= 255;
    }
    void dfs(const string& s, int start, int parts, string& path, vector<string>& res) {
        if (parts == 4) {
            if (start == (int)s.size()) res.push_back(path);
            return;
        }
        for (int len = 1; len <= 3 && start + len <= (int)s.size(); ++len) {
            string seg = s.substr(start, len);
            if (!valid(seg)) continue;
            if (!path.empty()) path.push_back('.');
            path += seg;
            dfs(s, start + len, parts + 1, path, res);
            path.resize(path.size() - len - (parts > 0 ? 1 : 0));
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        string path;
        dfs(s, 0, 0, path, res);
        return res;
    }
};
