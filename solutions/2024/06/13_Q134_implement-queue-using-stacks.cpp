/*
 * Day: 134 | Date: 2024-06-13
 * Q134: Implement Queue using Stacks
 * Difficulty: Easy
 * Pattern: Queue/Deque
 * Section: Stacks & Queues
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class MyQueue {
    stack<int> inSt, outSt;
    void pour() {
        if (outSt.empty()) while (!inSt.empty()) { outSt.push(inSt.top()); inSt.pop(); }
    }
public:
    MyQueue() {}
    void push(int x) { inSt.push(x); }
    int pop() { pour(); int v = outSt.top(); outSt.pop(); return v; }
    int peek() { pour(); return outSt.top(); }
    bool empty() { pour(); return outSt.empty(); }
};
