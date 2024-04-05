/*
 * Day: 65 | Date: 2024-04-05
 * Q065: Longest Substring with At Most K Distinct Characters
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
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if (k == 0) return 0;
        unordered_map<char, int> cnt;
        int left = 0, best = 0;
        for (int right = 0; right < (int)s.size(); ++right) {
            if (++cnt[s[right]] == 1 && (int)cnt.size() > k) {
                while ((int)cnt.size() > k) {
                    if (--cnt[s[left]] == 0) cnt.erase(s[left]);
                    ++left;
                }
            }
            best = max(best, right - left + 1);
        }
        return best;
    }
};
