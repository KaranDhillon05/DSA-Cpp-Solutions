/*
 * Day: 474 | Date: 2025-05-19
 * Q474: Hit Counter
 * Difficulty: Medium
 * Pattern: Design
 * Section: 13 Design
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class HitCounter {
    queue<int> hits;
public:
    HitCounter() {}
    void hit(int timestamp) { hits.push(timestamp); }
    int getHits(int timestamp) {
        while (!hits.empty() && hits.front() <= timestamp - 300) hits.pop();
        return hits.size();
    }
};
