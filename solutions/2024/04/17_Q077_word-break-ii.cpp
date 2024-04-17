/*
 * Day: 77 | Date: 2024-04-17
 * Q077: Word Break II
 * Difficulty: Hard
 * Pattern: DP / Backtracking
 * Section: 2.3
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
    unordered_set<string> dict;
    unordered_map<int, vector<string>> memo;
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        dict = unordered_set<string>(wordDict.begin(), wordDict.end());
        memo.clear();
        return dfs(s, 0);
    }
private:
    vector<string> dfs(const string& s, int start) {
        if (memo.count(start)) return memo[start];
        if (start == (int)s.size()) return {""};
        vector<string> res;
        for (int end = start + 1; end <= (int)s.size(); ++end) {
            string word = s.substr(start, end - start);
            if (!dict.count(word)) continue;
            for (const string& tail : dfs(s, end)) {
                res.push_back(tail.empty() ? word : word + " " + tail);
            }
        }
        return memo[start] = res;
    }
};
