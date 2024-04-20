/*
 * Day: 80 | Date: 2024-04-20
 * Q080: Minimum Remove to Make Valid Parentheses
 * Difficulty: Medium
 * Pattern: Stack
 * Section: 2.4
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string res;
        int bal = 0;
        for (char c : s) {
            if (c == '(') { res.push_back(c); ++bal; }
            else if (c == ')') {
                if (bal > 0) { res.push_back(c); --bal; }
            } else res.push_back(c);
        }
        while (bal-- > 0) {
            for (int i = (int)res.size() - 1; i >= 0; --i)
                if (res[i] == '(') { res.erase(i, 1); break; }
        }
        return res;
    }
};
