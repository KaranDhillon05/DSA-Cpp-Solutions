/*
 * Day: 132 | Date: 2024-06-11
 * Q132: First Negative in Every Window of Size K
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
    vector<int> firstNegativeInWindow(vector<int>& arr, int k) {
        deque<int> dq;
        vector<int> ans;
        for (int i = 0; i < (int)arr.size(); ++i) {
            if (arr[i] < 0) dq.push_back(i);
            if (i >= k - 1) {
                while (!dq.empty() && dq.front() <= i - k) dq.pop_front();
                ans.push_back(dq.empty() ? 0 : arr[dq.front()]);
            }
        }
        return ans;
    }
};
