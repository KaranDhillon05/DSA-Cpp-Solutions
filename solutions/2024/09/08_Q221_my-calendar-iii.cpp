/*
 * Day: 221 | Date: 2024-09-08
 * Q221: My Calendar III
 * Difficulty: Hard
 * Pattern: Segment Tree / BIT
 * Section: Trees
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class MyCalendarThree {
    map<int,int> timeline;
public:
    MyCalendarThree() {}
    int book(int start, int end) {
        timeline[start]++;
        timeline[end]--;
        int cur = 0, best = 0;
        for (auto& [_, delta] : timeline) {
            cur += delta;
            best = max(best, cur);
        }
        return best;
    }
};
