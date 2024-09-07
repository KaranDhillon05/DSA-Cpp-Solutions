/*
 * Day: 220 | Date: 2024-09-07
 * Q220: My Calendar II
 * Difficulty: Medium
 * Pattern: Segment Tree / BIT
 * Section: Trees
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class MyCalendarTwo {
    vector<pair<int,int>> once, twice;
    bool overlap(vector<pair<int,int>>& arr, int s, int e) {
        for (auto& [a, b] : arr) if (max(a, s) < min(b, e)) return true;
        return false;
    }
public:
    MyCalendarTwo() {}
    bool book(int start, int end) {
        if (overlap(twice, start, end)) return false;
        if (overlap(once, start, end)) twice.push_back({start, end});
        once.push_back({start, end});
        return true;
    }
};
