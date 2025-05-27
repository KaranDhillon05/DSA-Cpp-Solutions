/*
 * Day: 482 | Date: 2025-05-27
 * Q482: Random Pick with Weight
 * Difficulty: Medium
 * Pattern: Design
 * Section: 13 Design
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> prefix;
    int total;
    mt19937 rng{random_device{}()};
public:
    Solution(vector<int>& w) {
        for (int x : w) { total += x; prefix.push_back(total); }
    }
    int pickIndex() {
        int target = rng() % total + 1;
        return lower_bound(prefix.begin(), prefix.end(), target) - prefix.begin();
    }
};
