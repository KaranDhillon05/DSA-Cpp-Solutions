/*
 * Day: 483 | Date: 2025-05-28
 * Q483: Insert Delete GetRandom O(1)
 * Difficulty: Medium
 * Pattern: Design
 * Section: 13 Design
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class RandomizedSet {
    vector<int> arr;
    unordered_map<int,int> pos;
public:
    RandomizedSet() {}
    bool insert(int val) {
        if (pos.count(val)) return false;
        pos[val] = arr.size();
        arr.push_back(val);
        return true;
    }
    bool remove(int val) {
        if (!pos.count(val)) return false;
        int idx = pos[val];
        int last = arr.back();
        arr[idx] = last;
        pos[last] = idx;
        arr.pop_back();
        pos.erase(val);
        return true;
    }
    int getRandom() { return arr[rand() % arr.size()]; }
};
