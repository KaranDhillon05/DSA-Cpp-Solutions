/*
 * Day: 127 | Date: 2024-06-06
 * Q127: Maximum Width Ramp
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
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        for (int i = 0; i < n; ++i) {
            if (st.empty() || nums[st.top()] > nums[i]) st.push(i);
        }
        int ans = 0;
        for (int j = n - 1; j >= 0; --j) {
            while (!st.empty() && nums[st.top()] <= nums[j]) {
                ans = max(ans, j - st.top());
                st.pop();
            }
        }
        return ans;
    }
};
