/*
 * Day: 83 | Date: 2024-04-23
 * Q083: Remove All Adjacent Duplicates In String
 * Difficulty: Easy
 * Pattern: Stack
 * Section: 2.4
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        string st;
        for (char c : s) {
            if (!st.empty() && st.back() == c) st.pop_back();
            else st.push_back(c);
        }
        return st;
    }
};
