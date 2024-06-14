/*
 * Day: 135 | Date: 2024-06-14
 * Q135: Design Circular Queue
 * Difficulty: Medium
 * Pattern: Queue/Deque
 * Section: Stacks & Queues
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class MyCircularQueue {
    vector<int> a;
    int head = 0, cnt = 0;
public:
    MyCircularQueue(int k) : a(k) {}
    bool enQueue(int value) {
        if (isFull()) return false;
        a[(head + cnt) % (int)a.size()] = value;
        ++cnt;
        return true;
    }
    bool deQueue() {
        if (isEmpty()) return false;
        head = (head + 1) % (int)a.size();
        --cnt;
        return true;
    }
    int Front() { return isEmpty() ? -1 : a[head]; }
    int Rear() { return isEmpty() ? -1 : a[(head + cnt - 1) % (int)a.size()]; }
    bool isEmpty() { return cnt == 0; }
    bool isFull() { return cnt == (int)a.size(); }
};
