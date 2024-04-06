/*
 * Day: 66 | Date: 2024-04-06
 * Q066: Longest Substring with At Most Two Distinct Characters
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
    int lengthOfLongestSubstringTwoDistinct(string s) {
        unordered_map<char, int> cnt;
        int left = 0, best = 0;
        for (int right = 0; right < (int)s.size(); ++right) {
            ++cnt[s[right]];
            while ((int)cnt.size() > 2) {
                if (--cnt[s[left]] == 0) cnt.erase(s[left]);
                ++left;
            }
            best = max(best, right - left + 1);
        }
        return best;
    }
};
