/*
 * Day: 139 | Date: 2024-06-18
 * Q139: Jump Game VI
 * Difficulty: Medium
 * Pattern: Queue/Deque
 * Section: Stacks & Queues
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n);
        dp[0] = nums[0];
        deque<int> dq;
        dq.push_back(0);
        for (int i = 1; i < n; ++i) {
            while (!dq.empty() && dq.front() < i - k) dq.pop_front();
            dp[i] = nums[i] + dp[dq.front()];
            while (!dq.empty() && dp[dq.back()] <= dp[i]) dq.pop_back();
            dq.push_back(i);
        }
        return dp[n - 1];
    }
};
