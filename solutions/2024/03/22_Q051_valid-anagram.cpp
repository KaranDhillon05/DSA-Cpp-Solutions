/*
 * Day: 51 | Date: 2024-03-22
 * Q051: Valid Anagram
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
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        int cnt[26]{};
        for (char c : s) cnt[c - 'a']++;
        for (char c : t) if (--cnt[c - 'a'] < 0) return false;
        return true;
    }
};
