/*
 * Day: 30 | Date: 2024-03-01
 * Q030: Random Pick with Weight
 * Difficulty: Medium
 * Pattern: Prefix Sum
 * Section: 1.3 Prefix Sum
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> prefix;
    int total;
    mt19937 rng;
public:
    Solution(vector<int>& w) : rng(random_device{}()) {
        prefix = w;
        for (int i = 1; i < (int)prefix.size(); ++i) {
            prefix[i] += prefix[i - 1];
        }
        total = prefix.back();
    }

    int pickIndex() {
        uniform_int_distribution<int> dist(1, total);
        int target = dist(rng);
        return (int)(lower_bound(prefix.begin(), prefix.end(), target) - prefix.begin());
    }
};
