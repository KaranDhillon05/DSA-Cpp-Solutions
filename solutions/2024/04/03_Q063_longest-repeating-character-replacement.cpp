/*
 * Day: 63 | Date: 2024-04-03
 * Q063: Longest Repeating Character Replacement
 * Difficulty: Medium
 * Pattern: Sliding Window
 * Section: 2.2
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> cnt(26);
        int left = 0, maxFreq = 0, best = 0;
        for (int right = 0; right < (int)s.size(); ++right) {
            maxFreq = max(maxFreq, ++cnt[s[right] - 'A']);
            while (right - left + 1 - maxFreq > k) --cnt[s[left++] - 'A'];
            best = max(best, right - left + 1);
        }
        return best;
    }
};
