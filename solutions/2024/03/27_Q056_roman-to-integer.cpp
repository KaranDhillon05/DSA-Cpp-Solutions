/*
 * Day: 56 | Date: 2024-03-27
 * Q056: Roman to Integer
 * Difficulty: Easy
 * Pattern: String Basics
 * Section: 2.1
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> m{{'I',1},{'V',5},{'X',10},{'L',50},
                                   {'C',100},{'D',500},{'M',1000}};
        int res = 0;
        for (int i = 0; i < (int)s.size(); ++i) {
            if (i + 1 < (int)s.size() && m[s[i]] < m[s[i + 1]]) res -= m[s[i]];
            else res += m[s[i]];
        }
        return res;
    }
};
