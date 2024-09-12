/*
 * Day: 225 | Date: 2024-09-12
 * Q225: Data Stream as Disjoint Intervals
 * Difficulty: Hard
 * Pattern: Segment Tree / BIT
 * Section: Trees
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class SummaryRanges {
    set<int> vals;
public:
    SummaryRanges() {}
    void addNum(int value) { vals.insert(value); }
    vector<vector<int>> getIntervals() {
        vector<vector<int>> ans;
        if (vals.empty()) return ans;
        int start = *vals.begin(), prev = start;
        for (int x : vals) {
            if (x > prev + 1) { ans.push_back({start, prev}); start = x; }
            prev = x;
        }
        ans.push_back({start, prev});
        return ans;
    }
};
