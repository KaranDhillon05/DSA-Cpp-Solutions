/*
 * Day: 14 | Date: 2024-02-14
 * Q014: Minimum Window Substring
 * Difficulty: Hard
 * Pattern: Sliding Window
 * Section: 1.2 Sliding Window
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty() || s.size() < t.size()) return "";
        vector<int> need(128, 0), have(128, 0);
        for (char c : t) ++need[(unsigned char)c];
        int required = (int)t.size(), formed = 0;
        int l = 0, bestLen = INT_MAX, bestStart = 0;
        for (int r = 0; r < (int)s.size(); ++r) {
            unsigned char c = (unsigned char)s[r];
            if (need[c] > 0) {
                ++have[c];
                if (have[c] <= need[c]) ++formed;
            }
            while (formed == required) {
                if (r - l + 1 < bestLen) {
                    bestLen = r - l + 1;
                    bestStart = l;
                }
                unsigned char left = (unsigned char)s[l++];
                if (need[left] > 0 && have[left]-- == need[left]) --formed;
            }
        }
        return bestLen == INT_MAX ? "" : s.substr(bestStart, bestLen);
    }
};
