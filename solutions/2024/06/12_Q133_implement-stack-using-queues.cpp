/*
 * Day: 133 | Date: 2024-06-12
 * Q133: Implement Stack using Queues
 * Difficulty: Easy
 * Pattern: Queue/Deque
 * Section: Stacks & Queues
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class MyStack {
    queue<int> q;
public:
    MyStack() {}
    void push(int x) {
        q.push(x);
        for (int i = 1; i < (int)q.size(); ++i) { q.push(q.front()); q.pop(); }
    }
    int pop() { int v = q.front(); q.pop(); return v; }
    int top() { return q.front(); }
    bool empty() { return q.empty(); }
};
