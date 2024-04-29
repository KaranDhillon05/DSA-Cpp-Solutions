/*
 * Day: 89 | Date: 2024-04-29
 * Q089: Is Subsequence
 * Difficulty: Easy
 * Pattern: Two Pointers
 * Section: 2.4
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0;
        for (char c : t) if (i < (int)s.size() && s[i] == c) ++i;
        return i == (int)s.size();
    }
};
