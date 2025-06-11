/*
 * Day: 497 | Date: 2025-06-11
 * Q497: My Calendar I
 * Difficulty: Medium
 * Pattern: Design
 * Section: 13 Design
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class MyCalendar {
    vector<pair<int,int>> bookings;
public:
    MyCalendar() {}
    bool book(int start, int end) {
        for (auto& [s, e] : bookings)
            if (max(start, s) < min(end, e)) return false;
        bookings.push_back({start, end});
        return true;
    }
};
