/*
 * Day: 241 | Date: 2024-09-28
 * Q241: Maximum Frequency Stack
 * Difficulty: Hard
 * Pattern: Top-K Pattern
 * Section: Heaps & Priority Queues
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class FreqStack {
    unordered_map<int,int> freq;
    unordered_map<int, stack<int>> group;
    int maxFreq = 0;
public:
    void push(int val) {
        int f = ++freq[val];
        group[f].push(val);
        maxFreq = max(maxFreq, f);
    }
    int pop() {
        int val = group[maxFreq].top();
        group[maxFreq].pop();
        if (group[maxFreq].empty()) --maxFreq;
        return val;
    }
};
