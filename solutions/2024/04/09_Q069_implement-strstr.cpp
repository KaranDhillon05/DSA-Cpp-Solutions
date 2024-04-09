/*
 * Day: 69 | Date: 2024-04-09
 * Q069: Implement strStr()
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
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        int n = haystack.size(), m = needle.size();
        vector<int> lps(m, 0);
        for (int i = 1, len = 0; i < m; ) {
            if (needle[i] == needle[len]) lps[i++] = ++len;
            else if (len) len = lps[len - 1];
            else lps[i++] = 0;
        }
        for (int i = 0, j = 0; i < n; ) {
            if (haystack[i] == needle[j]) { ++i; ++j; }
            if (j == m) return i - j;
            else if (i < n && haystack[i] != needle[j]) {
                if (j) j = lps[j - 1];
                else ++i;
            }
        }
        return -1;
    }
};
