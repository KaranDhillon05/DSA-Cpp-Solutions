/*
 * Day: 240 | Date: 2024-09-27
 * Q240: Task Scheduler
 * Difficulty: Medium
 * Pattern: Top-K Pattern
 * Section: Heaps & Priority Queues
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> freq;
        for (char c : tasks) ++freq[c];
        priority_queue<int> pq;
        for (auto& [c,f] : freq) pq.push(f);
        int time = 0;
        queue<pair<int,int>> cool;
        while (!pq.empty() || !cool.empty()) {
            ++time;
            if (!pq.empty()) {
                int cnt = pq.top(); pq.pop();
                if (--cnt > 0) cool.push({cnt, time + n});
            }
            if (!cool.empty() && cool.front().second == time) {
                pq.push(cool.front().first);
                cool.pop();
            }
        }
        return time;
    }
};
