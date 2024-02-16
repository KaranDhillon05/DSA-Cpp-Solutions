/*
 * Day: 16 | Date: 2024-02-16
 * Q016: Permutation in String
 * Difficulty: Medium
 * Pattern: Sliding Window
 * Section: 1.2 Sliding Window
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        vector<int> need(26, 0), window(26, 0);
        for (char c : s1) ++need[c - 'a'];
        int k = (int)s1.size();
        for (int i = 0; i < (int)s2.size(); ++i) {
            ++window[s2[i] - 'a'];
            if (i >= k) --window[s2[i - k] - 'a'];
            if (i >= k - 1 && window == need) return true;
        }
        return false;
    }
};
