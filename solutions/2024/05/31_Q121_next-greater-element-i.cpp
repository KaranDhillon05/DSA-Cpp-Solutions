/*
 * Day: 121 | Date: 2024-05-31
 * Q121: Next Greater Element I
 * Difficulty: Easy
 * Pattern: Monotonic Stack
 * Section: Stacks & Queues
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nxt;
        stack<int> st;
        for (int x : nums2) {
            while (!st.empty() && st.top() < x) { nxt[st.top()] = x; st.pop(); }
            st.push(x);
        }
        vector<int> ans;
        for (int x : nums1) ans.push_back(nxt.count(x) ? nxt[x] : -1);
        return ans;
    }
};
