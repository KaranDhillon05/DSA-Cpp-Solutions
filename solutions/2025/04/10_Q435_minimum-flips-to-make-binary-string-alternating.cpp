/*
 * Day: 435 | Date: 2025-04-10
 * Q435: Minimum Flips to Make Binary String Alternating
 * Difficulty: Medium
 * Pattern: Greedy
 * Section: 11 Greedy
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minFlips(string s) {
        int n = s.size(), alt0 = 0, alt1 = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] != char('0' + (i % 2))) ++alt0;
            if (s[i] != char('0' + ((i + 1) % 2))) ++alt1;
        }
        return min(alt0, alt1);
    }
};
