/*
 * Day: 494 | Date: 2025-06-08
 * Q494: First Unique Number
 * Difficulty: Medium
 * Pattern: Design
 * Section: 13 Design
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class FirstUnique {
    queue<int> q;
    unordered_map<int,int> cnt;
public:
    FirstUnique(vector<int>& nums) {
        for (int x : nums) add(x);
    }
    int showFirstUnique() {
        while (!q.empty() && cnt[q.front()] > 1) q.pop();
        return q.empty() ? -1 : q.front();
    }
    void add(int value) {
        ++cnt[value];
        if (cnt[value] == 1) q.push(value);
    }
};
