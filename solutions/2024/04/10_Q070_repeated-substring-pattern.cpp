/*
 * Day: 70 | Date: 2024-04-10
 * Q070: Repeated Substring Pattern
 * Difficulty: Easy
 * Pattern: KMP
 * Section: 2.3
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        vector<int> lps(n, 0);
        for (int i = 1, len = 0; i < n; ) {
            if (s[i] == s[len]) lps[i++] = ++len;
            else if (len) len = lps[len - 1];
            else lps[i++] = 0;
        }
        int len = lps[n - 1];
        return len > 0 && n % (n - len) == 0;
    }
};
