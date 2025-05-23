/*
 * Day: 478 | Date: 2025-05-23
 * Q478: Design Underground System
 * Difficulty: Medium
 * Pattern: Design
 * Section: 13 Design
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class UndergroundSystem {
    unordered_map<int, pair<string,int>> checkIn;
    unordered_map<string, long long> total;
    unordered_map<string, int> count;
public:
    UndergroundSystem() {}
    void checkIn(int id, string station, int t) { checkIn[id] = {station, t}; }
    void checkOut(int id, string station, int t) {
        auto [start, time] = checkIn[id];
        string route = start + "->" + station;
        total[route] += t - time;
        ++count[route];
        checkIn.erase(id);
    }
    double getAverageTime(string start, string end) {
        string route = start + "->" + end;
        return (double)total[route] / count[route];
    }
};
