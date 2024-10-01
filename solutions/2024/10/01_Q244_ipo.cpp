/*
 * Day: 244 | Date: 2024-10-01
 * Q244: IPO
 * Difficulty: Hard
 * Pattern: Two-Heap Pattern
 * Section: Heaps & Priority Queues
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int,int>> projects(n);
        for (int i = 0; i < n; ++i) projects[i] = {capital[i], profits[i]};
        sort(projects.begin(), projects.end());
        priority_queue<int> pq;
        int idx = 0;
        for (int i = 0; i < k; ++i) {
            while (idx < n && projects[idx].first <= w) {
                pq.push(projects[idx].second);
                ++idx;
            }
            if (pq.empty()) break;
            w += pq.top(); pq.pop();
        }
        return w;
    }
};
