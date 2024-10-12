/*
 * Day: 255 | Date: 2024-10-12
 * Q255: Minimum Number of Refueling Stops
 * Difficulty: Hard
 * Pattern: Two-Heap Pattern
 * Section: Heaps & Priority Queues
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> pq;
        int i = 0, n = stations.size(), fuel = startFuel, stops = 0;
        while (fuel < target) {
            while (i < n && stations[i][0] <= fuel) {
                pq.push(stations[i][1]);
                ++i;
            }
            if (pq.empty()) return -1;
            fuel += pq.top(); pq.pop();
            ++stops;
        }
        return stops;
    }
};
