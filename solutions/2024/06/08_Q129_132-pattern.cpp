/*
 * Day: 129 | Date: 2024-06-08
 * Q129: 132 Pattern
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
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftMin(n, nums[0]);
        for (int i = 1; i < n; ++i) leftMin[i] = min(leftMin[i - 1], nums[i]);
        stack<int> st;
        for (int k = n - 1; k >= 0; --k) {
            while (!st.empty() && nums[k] > nums[st.top()]) {
                if (leftMin[k] < nums[st.top()]) return true;
                st.pop();
            }
            st.push(k);
        }
        return false;
    }
};
