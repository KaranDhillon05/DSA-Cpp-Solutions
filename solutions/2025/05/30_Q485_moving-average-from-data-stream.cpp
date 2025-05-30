/*
 * Day: 485 | Date: 2025-05-30
 * Q485: Moving Average from Data Stream
 * Difficulty: Easy
 * Pattern: Design
 * Section: 13 Design
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class MovingAverage {
    queue<int> q;
    int cap, sum = 0;
public:
    MovingAverage(int size) : cap(size) {}
    double next(int val) {
        q.push(val);
        sum += val;
        if ((int)q.size() > cap) { sum -= q.front(); q.pop(); }
        return (double)sum / q.size();
    }
};
