/*
 * Day: 68 | Date: 2024-04-08
 * Q068: Palindromic Substrings
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
    int countSubstrings(string s) {
        int n = s.size(), count = 0;
        auto expand = [&](int l, int r) {
            while (l >= 0 && r < n && s[l] == s[r]) { ++count; --l; ++r; }
        };
        for (int i = 0; i < n; ++i) { expand(i, i); expand(i, i + 1); }
        return count;
    }
};
