/*
 * Day: 434 | Date: 2025-04-09
 * Q434: Minimum Deletions to Make Character Frequencies Unique
 * Difficulty: Medium
 * Pattern: Greedy
 * Section: 11 Greedy
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(26);
        for (char c : s) ++freq[c - 'a'];
        sort(freq.begin(), freq.end());
        int res = 0;
        for (int i = 24; i >= 0; --i) {
            if (freq[i] == 0) continue;
            if (freq[i] >= freq[i + 1]) {
                res += freq[i] - (freq[i + 1] - 1);
                freq[i] = freq[i + 1] - 1;
            }
        }
        return res;
    }
};
