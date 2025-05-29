/*
 * Day: 484 | Date: 2025-05-29
 * Q484: Insert Delete GetRandom O(1) Duplicates
 * Difficulty: Hard
 * Pattern: Design
 * Section: 13 Design
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class RandomizedCollection {
    vector<pair<int,int>> arr;
    unordered_map<int, unordered_set<int>> pos;
public:
    RandomizedCollection() {}
    bool insert(int val) {
        arr.push_back({val, (int)pos[val].size()});
        pos[val].insert(arr.size() - 1);
        return pos[val].size() == 1;
    }
    bool remove(int val) {
        if (!pos.count(val) || pos[val].empty()) return false;
        int idx = *pos[val].begin();
        auto last = arr.back();
        arr[idx] = last;
        pos[last.first].erase(arr.size() - 1);
        pos[last.first].insert(idx);
        pos[val].erase(idx);
        arr.pop_back();
        if (pos[val].empty()) pos.erase(val);
        return true;
    }
    int getRandom() { return arr[rand() % arr.size()].first; }
};
