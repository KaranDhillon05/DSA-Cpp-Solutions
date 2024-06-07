/*
 * Day: 128 | Date: 2024-06-07
 * Q128: Online Stock Span
 * Difficulty: Medium
 * Pattern: Monotonic Stack
 * Section: Stacks & Queues
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class StockSpanner {
    vector<int> st, span;
public:
    StockSpanner() {}
    int next(int price) {
        int s = 1;
        while (!st.empty() && st.back() <= price) { s += span.back(); st.pop_back(); span.pop_back(); }
        st.push_back(price);
        span.push_back(s);
        return s;
    }
};
