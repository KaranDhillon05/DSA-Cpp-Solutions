/*
 * Day: 426 | Date: 2025-04-01
 * Q426: Assign Cookies
 * Difficulty: Easy
 * Pattern: Greedy
 * Section: 11 Greedy
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i = 0, j = 0;
        while (i < (int)g.size() && j < (int)s.size()) {
            if (s[j] >= g[i]) ++i;
            ++j;
        }
        return i;
    }
};
