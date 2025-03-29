/*
 * Day: 423 | Date: 2025-03-29
 * Q423: Job Sequencing Problem
 * Difficulty: Medium
 * Pattern: Greedy
 * Section: 11 Greedy
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jobSequencing(vector<int>& profit, vector<int>& deadline) {
        int n = profit.size();
        vector<pair<int,int>> jobs;
        for (int i = 0; i < n; ++i) jobs.push_back({profit[i], deadline[i]});
        sort(jobs.begin(), jobs.end(), greater<pair<int,int>>());
        int maxD = *max_element(deadline.begin(), deadline.end());
        vector<int> slot(maxD + 1, -1);
        int res = 0;
        for (auto& [p, d] : jobs) {
            for (int day = d; day >= 1; --day) {
                if (slot[day] == -1) { slot[day] = 1; res += p; break; }
            }
        }
        return res;
    }
};
