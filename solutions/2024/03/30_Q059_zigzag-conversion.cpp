/*
 * Day: 59 | Date: 2024-03-30
 * Q059: ZigZag Conversion
 * Difficulty: Medium
 * Pattern: String Basics
 * Section: 2.1
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        vector<string> rows(numRows);
        int row = 0, step = 1;
        for (char c : s) {
            rows[row] += c;
            if (row == 0) step = 1;
            else if (row == numRows - 1) step = -1;
            row += step;
        }
        string res;
        for (const string& r : rows) res += r;
        return res;
    }
};
