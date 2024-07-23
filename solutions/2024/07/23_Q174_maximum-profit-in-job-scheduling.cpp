/*
 * Day: 174 | Date: 2024-07-23
 * Q174: Maximum Profit in Job Scheduling
 * Difficulty: Hard
 * Pattern: Bisect
 * Section: Binary Search
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jobScheduling(vector<int>& start, vector<int>& end, vector<int>& profit) {
        int n = start.size();
        vector<array<int,3>> jobs(n);
        for (int i = 0; i < n; ++i) jobs[i] = {start[i], end[i], profit[i]};
        sort(jobs.begin(), jobs.end(), [](auto& a, auto& b){ return a[1] < b[1]; });
        vector<int> ends, dp;
        for (auto& j : jobs) {
            int idx = upper_bound(ends.begin(), ends.end(), j[0]) - ends.begin() - 1;
            int val = j[2] + (idx >= 0 ? dp[idx] : 0);
            if (ends.empty() || val > dp.back()) { ends.push_back(j[1]); dp.push_back(val); }
            else dp.back() = max(dp.back(), val);
        }
        return dp.empty() ? 0 : dp.back();
    }
};
