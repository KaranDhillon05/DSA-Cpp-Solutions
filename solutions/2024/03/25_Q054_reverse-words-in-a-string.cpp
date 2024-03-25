/*
 * Day: 54 | Date: 2024-03-25
 * Q054: Reverse Words in a String
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
    string reverseWords(string s) {
        string res, word;
        for (int i = (int)s.size() - 1; i >= 0; --i) {
            if (s[i] != ' ') {
                word = s[i] + word;
            } else if (!word.empty()) {
                if (!res.empty()) res += ' ';
                res += word;
                word.clear();
            }
        }
        if (!word.empty()) {
            if (!res.empty()) res += ' ';
            res += word;
        }
        return res;
    }
};
