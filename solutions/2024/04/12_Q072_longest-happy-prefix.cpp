/*
 * Day: 72 | Date: 2024-04-12
 * Q072: Longest Happy Prefix
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
    string longestPrefix(string s) {
        int n = s.size();
        vector<int> lps(n, 0);
        for (int i = 1, len = 0; i < n; ) {
            if (s[i] == s[len]) lps[i++] = ++len;
            else if (len) len = lps[len - 1];
            else lps[i++] = 0;
        }
        return s.substr(0, lps[n - 1]);
    }
};
