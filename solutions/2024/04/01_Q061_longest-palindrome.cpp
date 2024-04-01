/*
 * Day: 61 | Date: 2024-04-01
 * Q061: Longest Palindrome
 * Difficulty: Easy
 * Pattern: Hashing
 * Section: 2.1
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        int cnt[128]{};
        for (char c : s) cnt[c]++;
        int len = 0;
        bool odd = false;
        for (int c = 0; c < 128; ++c) {
            if (!cnt[c]) continue;
            len += cnt[c] / 2 * 2;
            if (cnt[c] % 2) odd = true;
        }
        return len + (odd ? 1 : 0);
    }
};
