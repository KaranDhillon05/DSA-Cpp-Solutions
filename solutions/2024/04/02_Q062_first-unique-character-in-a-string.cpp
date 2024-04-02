/*
 * Day: 62 | Date: 2024-04-02
 * Q062: First Unique Character in a String
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
    int firstUniqChar(string s) {
        int cnt[26]{};
        for (char c : s) cnt[c - 'a']++;
        for (int i = 0; i < (int)s.size(); ++i)
            if (cnt[s[i] - 'a'] == 1) return i;
        return -1;
    }
};
