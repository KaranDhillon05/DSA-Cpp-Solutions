/*
 * Day: 252 | Date: 2024-10-09
 * Q252: Single-Threaded CPU
 * Difficulty: Medium
 * Pattern: Two-Heap Pattern
 * Section: Heaps & Priority Queues
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        for (int i = 0; i < (int)tasks.size(); ++i) tasks[i].push_back(i);
        sort(tasks.begin(), tasks.end());
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        vector<int> res;
        long long t = 0;
        int i = 0, n = tasks.size();
        while (i < n || !pq.empty()) {
            if (pq.empty()) t = max(t, (long long)tasks[i][0]);
            while (i < n && tasks[i][0] <= t) {
                pq.push({tasks[i][1], tasks[i][2]});
                ++i;
            }
            auto [dur, idx] = pq.top(); pq.pop();
            res.push_back(idx);
            t += dur;
        }
        return res;
    }
};
