/*
 * Day: 450 | Date: 2025-04-25
 * Q450: Word Pattern
 * Difficulty: Easy
 * Pattern: Hashing
 * Section: 12 Hashing & Math
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> p2s;
        unordered_map<string, char> s2p;
        stringstream ss(s);
        string word;
        int i = 0;
        while (ss >> word) {
            if (i >= (int)pattern.size()) return false;
            char p = pattern[i++];
            if (p2s.count(p) && p2s[p] != word) return false;
            if (s2p.count(word) && s2p[word] != p) return false;
            p2s[p] = word;
            s2p[word] = p;
        }
        return i == (int)pattern.size();
    }
};
