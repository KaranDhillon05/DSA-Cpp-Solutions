/*
 * Day: 250 | Date: 2024-10-07
 * Q250: Employee Free Time
 * Difficulty: Hard
 * Pattern: Two-Heap Pattern
 * Section: Heaps & Priority Queues
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

struct Interval { int start, end; };

class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        vector<Interval> all;
        for (auto& emp : schedule)
            for (auto& iv : emp) all.push_back(iv);
        sort(all.begin(), all.end(), [](auto& a, auto& b){ return a.start < b.start; });
        priority_queue<int, vector<int>, greater<int>> pq;
        vector<Interval> res;
        for (auto& iv : all) {
            while (!pq.empty() && pq.top() <= iv.start) pq.pop();
            if (!pq.empty() && pq.top() < iv.start)
                res.push_back({pq.top(), iv.start});
            pq.push(iv.end);
        }
        return res;
    }
};
