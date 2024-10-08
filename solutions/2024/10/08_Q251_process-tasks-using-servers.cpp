/*
 * Day: 251 | Date: 2024-10-08
 * Q251: Process Tasks Using Servers
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
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        using T = tuple<int,int,int>;
        priority_queue<T, vector<T>, greater<T>> free, busy;
        for (int i = 0; i < (int)servers.size(); ++i) free.push({servers[i], i, 0});
        vector<int> ans;
        long long t = 0;
        for (int j = 0; j < (int)tasks.size(); ++j) {
            t = max(t, (long long)j);
            while (!busy.empty() && get<0>(busy.top()) <= t) {
                auto [end, w, idx] = busy.top(); busy.pop();
                free.push({w, idx, 0});
            }
            while (!free.empty() && j < (int)tasks.size()) {
                auto [w, idx, _] = free.top(); free.pop();
                ans.push_back(idx);
                busy.push({t + tasks[j], w, idx});
                ++j;
            }
            if (j < (int)tasks.size()) {
                t = get<0>(busy.top());
                --j;
            }
        }
        return ans;
    }
};
