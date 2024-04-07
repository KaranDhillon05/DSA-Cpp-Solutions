/*
 * Day: 67 | Date: 2024-04-07
 * Q067: Longest Palindromic Substring
 * Difficulty: Medium
 * Pattern: Expand Around Center
 * Section: 2.2
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size(), start = 0, maxLen = 1;
        auto expand = [&](int l, int r) {
            while (l >= 0 && r < n && s[l] == s[r]) { --l; ++r; }
            if (r - l - 1 > maxLen) { start = l + 1; maxLen = r - l - 1; }
        };
        for (int i = 0; i < n; ++i) { expand(i, i); expand(i, i + 1); }
        return s.substr(start, maxLen);
    }
};
