/*
 * Day: 490 | Date: 2025-06-04
 * Q490: Max Stack
 * Difficulty: Hard
 * Pattern: Design
 * Section: 13 Design
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class MaxStack {
    stack<int> st, maxs;
public:
    MaxStack() {}
    void push(int x) {
        st.push(x);
        maxs.push(maxs.empty() ? x : max(maxs.top(), x));
    }
    int pop() { int v = st.top(); st.pop(); maxs.pop(); return v; }
    int top() { return st.top(); }
    int peekMax() { return maxs.top(); }
    int popMax() {
        stack<int> tmp;
        while (st.top() != maxs.top()) { tmp.push(st.top()); st.pop(); maxs.pop(); }
        int v = st.top(); st.pop(); maxs.pop();
        while (!tmp.empty()) { push(tmp.top()); tmp.pop(); }
        return v;
    }
};
