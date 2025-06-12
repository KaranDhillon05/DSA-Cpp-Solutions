/*
 * Day: 498 | Date: 2025-06-12
 * Q498: My Calendar II
 * Difficulty: Medium
 * Pattern: Design
 * Section: 13 Design
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class MyCalendarTwo {
    vector<pair<int,int>> once, twice;
public:
    MyCalendarTwo() {}
    bool book(int start, int end) {
        for (auto& [s, e] : twice)
            if (max(start, s) < min(end, e)) return false;
        vector<pair<int,int>> overlap;
        for (auto& [s, e] : once) {
            int os = max(start, s), oe = min(end, e);
            if (os < oe) overlap.push_back({os, oe});
        }
        for (auto& o : overlap) twice.push_back(o);
        once.push_back({start, end});
        return true;
    }
};
