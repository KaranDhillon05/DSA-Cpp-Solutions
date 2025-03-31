/*
 * Day: 425 | Date: 2025-03-31
 * Q425: Meeting Rooms II
 * Difficulty: Medium
 * Pattern: Greedy
 * Section: 11 Greedy
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<int> start, end;
        for (auto& iv : intervals) { start.push_back(iv[0]); end.push_back(iv[1]); }
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        int rooms = 0, best = 0, i = 0, j = 0;
        while (i < (int)start.size()) {
            if (start[i] < end[j]) { ++rooms; ++i; }
            else { --rooms; ++j; }
            best = max(best, rooms);
        }
        return best;
    }
};
