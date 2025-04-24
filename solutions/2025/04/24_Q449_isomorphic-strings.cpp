/*
 * Day: 449 | Date: 2025-04-24
 * Q449: Isomorphic Strings
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
    bool isIsomorphic(string s, string t) {
        char mapS[128]{}, mapT[128]{};
        for (int i = 0; i < (int)s.size(); ++i) {
            if (mapS[s[i]] && mapS[s[i]] != t[i]) return false;
            if (mapT[t[i]] && mapT[t[i]] != s[i]) return false;
            mapS[s[i]] = t[i];
            mapT[t[i]] = s[i];
        }
        return true;
    }
};
