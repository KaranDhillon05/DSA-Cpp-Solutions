/*
 * Day: 64 | Date: 2024-04-04
 * Q064: Minimum Window Substring
 * Difficulty: Hard
 * Pattern: Sliding Window
 * Section: 2.2
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> need(128), have(128);
        int required = 0;
        for (char c : t) if (++need[c] == 1) ++required;
        int formed = 0, left = 0, start = 0, len = INT_MAX;
        for (int right = 0; right < (int)s.size(); ++right) {
            if (++have[s[right]] == need[s[right]]) ++formed;
            while (formed == required) {
                if (right - left + 1 < len) { len = right - left + 1; start = left; }
                if (--have[s[left]] < need[s[left]]) --formed;
                ++left;
            }
        }
        return len == INT_MAX ? "" : s.substr(start, len);
    }
};
