/*
 * Day: 445 | Date: 2025-04-20
 * Q445: Earliest Deadline First Scheduling
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
    int scheduleEDF(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end());
        priority_queue<int> pq;
        long long time = 0;
        for (auto& t : tasks) {
            time += t[1];
            pq.push(t[1]);
            if (time > t[0]) { time -= pq.top(); pq.pop(); }
        }
        return (int)pq.size();
    }
};
