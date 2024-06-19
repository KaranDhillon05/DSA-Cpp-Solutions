/*
 * Day: 140 | Date: 2024-06-19
 * Q140: Constrained Subsequence Sum
 * Difficulty: Hard
 * Pattern: Queue/Deque
 * Section: Stacks & Queues
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp = nums;
        deque<int> dq;
        int ans = INT_MIN;
        for (int i = 0; i < n; ++i) {
            if (!dq.empty()) dp[i] = max(dp[i], dp[dq.front()] + nums[i]);
            ans = max(ans, dp[i]);
            while (!dq.empty() && dp[dq.back()] <= dp[i]) dq.pop_back();
            dq.push_back(i);
            if (dq.front() <= i - k) dq.pop_front();
        }
        return ans;
    }
};
