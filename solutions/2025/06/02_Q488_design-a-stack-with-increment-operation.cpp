/*
 * Day: 488 | Date: 2025-06-02
 * Q488: Design a Stack With Increment Operation
 * Difficulty: Medium
 * Pattern: Design
 * Section: 13 Design
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class CustomStack {
    vector<int> st, inc;
public:
    CustomStack(int maxSize) : inc(maxSize) {}
    void push(int x) {
        if ((int)st.size() < (int)inc.size()) st.push_back(x);
    }
    int pop() {
        if (st.empty()) return -1;
        int idx = st.size() - 1;
        int val = st.back() + inc[idx];
        st.pop_back();
        if (!st.empty()) inc[idx - 1] += inc[idx];
        inc.pop_back();
        return val;
    }
    void increment(int k, int val) {
        k = min(k, (int)st.size());
        if (k > 0) inc[k - 1] += val;
    }
};
