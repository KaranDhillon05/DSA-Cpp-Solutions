/*
 * Day: 53 | Date: 2024-03-24
 * Q053: Longest Common Prefix
 * Difficulty: Easy
 * Pattern: String Basics
 * Section: 2.1
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        for (int i = 0; ; ++i) {
            char c = 0;
            for (const string& s : strs) {
                if (i == (int)s.size()) return s.substr(0, i);
                if (!c) c = s[i];
                else if (s[i] != c) return s.substr(0, i);
            }
        }
    }
};
