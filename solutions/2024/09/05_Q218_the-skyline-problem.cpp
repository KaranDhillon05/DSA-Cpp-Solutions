/*
 * Day: 218 | Date: 2024-09-05
 * Q218: The Skyline Problem
 * Difficulty: Hard
 * Pattern: Segment Tree / BIT
 * Section: Trees
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<long long, long long>> events;
        for (auto& b : buildings) {
            events.push_back({b[0], -b[2]});
            events.push_back({b[1], b[2]});
        }
        sort(events.begin(), events.end());
        multiset<long long> heights = {0};
        vector<vector<int>> ans;
        long long prev = 0;
        size_t i = 0;
        while (i < events.size()) {
            long long x = events[i].first;
            while (i < events.size() && events[i].first == x) {
                long long h = events[i].second;
                if (h < 0) heights.insert(-h); else heights.erase(heights.find(h));
                ++i;
            }
            long long cur = *heights.rbegin();
            if (cur != prev) { ans.push_back({(int)x, (int)cur}); prev = cur; }
        }
        return ans;
    }
};
