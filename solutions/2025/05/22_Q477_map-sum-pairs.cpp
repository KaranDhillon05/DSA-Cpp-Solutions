/*
 * Day: 477 | Date: 2025-05-22
 * Q477: Map Sum Pairs
 * Difficulty: Medium
 * Pattern: Design
 * Section: 13 Design
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class MapSum {
    unordered_map<string,int> vals;
    unordered_map<string,int> prefix;
public:
    MapSum() {}
    void insert(string key, int val) {
        int delta = val - vals[key];
        vals[key] = val;
        for (int i = 1; i <= (int)key.size(); ++i)
            prefix[key.substr(0, i)] += delta;
    }
    int sum(string prefixKey) { return prefix[prefixKey]; }
};
