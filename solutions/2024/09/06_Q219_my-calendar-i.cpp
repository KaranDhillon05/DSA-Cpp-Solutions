/*
 * Day: 219 | Date: 2024-09-06
 * Q219: My Calendar I
 * Difficulty: Medium
 * Pattern: Segment Tree / BIT
 * Section: Trees
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class MyCalendar {
    vector<pair<int,int>> books;
public:
    MyCalendar() {}
    bool book(int start, int end) {
        for (auto& [s, e] : books)
            if (max(s, start) < min(e, end)) return false;
        books.push_back({start, end});
        return true;
    }
};
