/*
 * Day: 496 | Date: 2025-06-10
 * Q496: Exam Room
 * Difficulty: Medium
 * Pattern: Design
 * Section: 13 Design
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class ExamRoom {
    int n;
    set<pair<int,int>> seats;
public:
    ExamRoom(int n) : n(n) { seats.insert({-1, -1}); }
    int seat() {
        int bestDist = -1, bestSeat = 0;
        auto it = seats.begin();
        auto prev = it++;
        while (it != seats.end()) {
            int dist;
            if (prev->first == -1) dist = it->first;
            else if (it->first == n) dist = n - 1 - prev->first;
            else dist = (it->first - prev->first) / 2;
            if (dist > bestDist) { bestDist = dist; bestSeat = prev->first == -1 ? 0 : prev->first + dist; }
            prev = it++;
        }
        seats.insert({bestSeat, -bestSeat});
        return bestSeat;
    }
    void leave(int p) {
        auto it = seats.find({p, -p});
        if (it != seats.end()) seats.erase(it);
    }
};
