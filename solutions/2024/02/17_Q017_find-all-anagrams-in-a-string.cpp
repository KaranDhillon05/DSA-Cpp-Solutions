/*
 * Day: 17 | Date: 2024-02-17
 * Q017: Find All Anagrams in a String
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
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        if (p.size() > s.size()) return res;
        vector<int> need(26, 0), window(26, 0);
        for (char c : p) ++need[c - 'a'];
        int k = (int)p.size();
        for (int i = 0; i < (int)s.size(); ++i) {
            ++window[s[i] - 'a'];
            if (i >= k) --window[s[i - k] - 'a'];
            if (i >= k - 1 && window == need) res.push_back(i - k + 1);
        }
        return res;
    }
};
