/*
 * Day: 489 | Date: 2025-06-03
 * Q489: Min Stack
 * Difficulty: Medium
 * Pattern: Design
 * Section: 13 Design
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class MinStack {
    stack<int> st, mins;
public:
    MinStack() {}
    void push(int val) {
        st.push(val);
        mins.push(mins.empty() ? val : min(mins.top(), val));
    }
    void pop() { st.pop(); mins.pop(); }
    int top() { return st.top(); }
    int getMin() { return mins.top(); }
};
