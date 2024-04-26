/*
 * Day: 86 | Date: 2024-04-26
 * Q086: Evaluate Reverse Polish Notation
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
    int evalRPN(vector<string>& tokens) {
        stack<long long> st;
        for (const string& t : tokens) {
            if (t.size() > 1 || isdigit(t[0])) st.push(stoll(t));
            else {
                long long b = st.top(); st.pop();
                long long a = st.top(); st.pop();
                if (t == "+") st.push(a + b);
                else if (t == "-") st.push(a - b);
                else if (t == "*") st.push(a * b);
                else st.push(a / b);
            }
        }
        return (int)st.top();
    }
};
