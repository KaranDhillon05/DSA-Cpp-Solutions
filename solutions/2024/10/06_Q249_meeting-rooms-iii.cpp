/*
 * Day: 249 | Date: 2024-10-06
 * Q249: Meeting Rooms III
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
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        priority_queue<int, vector<int>, greater<int>> free;
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> busy;
        for (int i = 0; i < n; ++i) free.push(i);
        vector<long long> cnt(n);
        for (auto& m : meetings) {
            long long s = m[0], e = m[1];
            while (!busy.empty() && busy.top().first <= s) {
                free.push(busy.top().second);
                busy.pop();
            }
            int room;
            if (!free.empty()) { room = free.top(); free.pop(); }
            else { room = busy.top().second; s = max(s, busy.top().first); busy.pop(); }
            cnt[room]++;
            busy.push({s + (e - m[0]), room});
        }
        int best = 0;
        for (int i = 1; i < n; ++i) if (cnt[i] > cnt[best]) best = i;
        return best;
    }
};
