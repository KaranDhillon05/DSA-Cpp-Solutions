/*
 * Day: 437 | Date: 2025-04-12
 * Q437: Maximum Score from Removing Substrings
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
    int maximumGain(string s, int x, int y) {
        auto remove = [](string& s, char a, char b, int score, int& total) {
            string st;
            for (char c : s) {
                if (!st.empty() && st.back() == a && c == b) { st.pop_back(); total += score; }
                else st.push_back(c);
            }
            s = st;
        };
        int res = 0;
        if (x >= y) { remove(s, 'a', 'b', x, res); remove(s, 'b', 'a', y, res); }
        else { remove(s, 'b', 'a', y, res); remove(s, 'a', 'b', x, res); }
        return res;
    }
};
