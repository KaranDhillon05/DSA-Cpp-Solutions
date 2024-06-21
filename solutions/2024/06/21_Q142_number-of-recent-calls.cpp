/*
 * Day: 142 | Date: 2024-06-21
 * Q142: Number of Recent Calls
 * Difficulty: Easy
 * Pattern: Queue/Deque
 * Section: Stacks & Queues
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class RecentCounter {
    queue<int> q;
public:
    RecentCounter() {}
    int ping(int t) {
        q.push(t);
        while (q.front() < t - 3000) q.pop();
        return (int)q.size();
    }
};
