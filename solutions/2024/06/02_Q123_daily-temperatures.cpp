/*
 * Day: 123 | Date: 2024-06-02
 * Q123: Daily Temperatures
 * Difficulty: Medium
 * Pattern: Monotonic Stack
 * Section: Stacks & Queues
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int n = T.size();
        vector<int> ans(n, 0);
        stack<int> st;
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && T[st.top()] < T[i]) { ans[st.top()] = i - st.top(); st.pop(); }
            st.push(i);
        }
        return ans;
    }
};
