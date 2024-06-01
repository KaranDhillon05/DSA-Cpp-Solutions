/*
 * Day: 122 | Date: 2024-06-01
 * Q122: Next Greater Element II
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
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> st;
        for (int i = 0; i < 2 * n; ++i) {
            int x = nums[i % n];
            while (!st.empty() && nums[st.top()] < x) { ans[st.top()] = x; st.pop(); }
            if (i < n) st.push(i);
        }
        return ans;
    }
};
