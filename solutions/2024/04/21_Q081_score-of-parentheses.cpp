/*
 * Day: 81 | Date: 2024-04-21
 * Q081: Score of Parentheses
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
    int scoreOfParentheses(string s) {
        stack<int> st;
        st.push(0);
        for (char c : s) {
            if (c == '(') st.push(0);
            else {
                int inner = st.top(); st.pop();
                int val = inner == 0 ? 1 : 2 * inner;
                st.top() += val;
            }
        }
        return st.top();
    }
};
