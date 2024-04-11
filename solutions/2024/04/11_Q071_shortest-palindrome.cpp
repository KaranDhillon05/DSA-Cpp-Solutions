/*
 * Day: 71 | Date: 2024-04-11
 * Q071: Shortest Palindrome
 * Difficulty: Hard
 * Pattern: KMP
 * Section: 2.3
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string shortestPalindrome(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());
        string comb = s + "#" + rev;
        vector<int> lps(comb.size(), 0);
        for (int i = 1, len = 0; i < (int)comb.size(); ) {
            if (comb[i] == comb[len]) lps[i++] = ++len;
            else if (len) len = lps[len - 1];
            else lps[i++] = 0;
        }
        return rev.substr(0, s.size() - lps.back()) + s;
    }
};
