/*
 * Day: 253 | Date: 2024-10-10
 * Q253: Furthest Building You Can Reach
 * Difficulty: Medium
 * Pattern: Two-Heap Pattern
 * Section: Heaps & Priority Queues
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i + 1 < (int)heights.size(); ++i) {
            int diff = heights[i+1] - heights[i];
            if (diff <= 0) continue;
            pq.push(diff);
            if ((int)pq.size() > ladders) {
                bricks -= pq.top(); pq.pop();
                if (bricks < 0) return i;
            }
        }
        return (int)heights.size() - 1;
    }
};
