/*
 * Day: 136 | Date: 2024-06-15
 * Q136: Design Circular Deque
 * Difficulty: Medium
 * Pattern: Queue/Deque
 * Section: Stacks & Queues
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class MyCircularDeque {
    vector<int> a;
    int head = 0, cnt = 0;
    int idx(int i) const { return (head + i) % (int)a.size(); }
public:
    MyCircularDeque(int k) : a(k) {}
    bool insertFront(int value) {
        if (isFull()) return false;
        head = (head - 1 + (int)a.size()) % (int)a.size();
        a[head] = value;
        ++cnt;
        return true;
    }
    bool insertLast(int value) {
        if (isFull()) return false;
        a[idx(cnt)] = value;
        ++cnt;
        return true;
    }
    bool deleteFront() {
        if (isEmpty()) return false;
        head = (head + 1) % (int)a.size();
        --cnt;
        return true;
    }
    bool deleteLast() {
        if (isEmpty()) return false;
        --cnt;
        return true;
    }
    int getFront() { return isEmpty() ? -1 : a[head]; }
    int getRear() { return isEmpty() ? -1 : a[idx(cnt - 1)]; }
    bool isEmpty() { return cnt == 0; }
    bool isFull() { return cnt == (int)a.size(); }
};
