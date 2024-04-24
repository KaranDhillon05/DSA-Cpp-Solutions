/*
 * Day: 84 | Date: 2024-04-24
 * Q084: Remove K Digits
 * Difficulty: Medium
 * Pattern: Stack / Greedy
 * Section: 2.4
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        string st;
        for (char c : num) {
            while (k > 0 && !st.empty() && st.back() > c) { st.pop_back(); --k; }
            st.push_back(c);
        }
        while (k-- > 0) st.pop_back();
        int i = 0;
        while (i < (int)st.size() && st[i] == '0') ++i;
        string res = st.substr(i);
        return res.empty() ? "0" : res;
    }
};
