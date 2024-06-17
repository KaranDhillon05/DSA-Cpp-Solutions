/*
 * Day: 138 | Date: 2024-06-17
 * Q138: Shortest Subarray with Sum at Least K
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
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> pref(n + 1);
        for (int i = 0; i < n; ++i) pref[i + 1] = pref[i] + nums[i];
        deque<int> dq;
        int ans = n + 1;
        for (int i = 0; i <= n; ++i) {
            while (!dq.empty() && pref[i] - pref[dq.front()] >= k) {
                ans = min(ans, i - dq.front());
                dq.pop_front();
            }
            while (!dq.empty() && pref[dq.back()] >= pref[i]) dq.pop_back();
            dq.push_back(i);
        }
        return ans <= n ? ans : -1;
    }
};
