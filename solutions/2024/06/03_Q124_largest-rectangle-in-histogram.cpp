/*
 * Day: 124 | Date: 2024-06-03
 * Q124: Largest Rectangle in Histogram
 * Difficulty: Hard
 * Pattern: Monotonic Stack
 * Section: Stacks & Queues
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        stack<int> st;
        int best = 0;
        for (int i = 0; i < (int)heights.size(); ++i) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                int h = heights[st.top()]; st.pop();
                int w = st.empty() ? i : i - st.top() - 1;
                best = max(best, h * w);
            }
            st.push(i);
        }
        heights.pop_back();
        return best;
    }
};
