/*
 * Day: 499 | Date: 2025-06-13
 * Q499: My Calendar III
 * Difficulty: Hard
 * Pattern: Design
 * Section: 13 Design
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class MyCalendarThree {
    map<int,int> delta;
public:
    MyCalendarThree() {}
    int book(int start, int end) {
        ++delta[start];
        --delta[end];
        int cur = 0, best = 0;
        for (auto& [_, d] : delta) { cur += d; best = max(best, cur); }
        return best;
    }
};
