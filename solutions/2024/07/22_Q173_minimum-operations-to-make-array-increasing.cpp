/*
 * Day: 173 | Date: 2024-07-22
 * Q173: Minimum Operations to Make Array Increasing
 * Difficulty: Hard
 * Pattern: Bisect
 * Section: Binary Search
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& target) {
        vector<int> tails;
        for (int x : target) {
            auto it = lower_bound(tails.begin(), tails.end(), x);
            if (it == tails.end()) tails.push_back(x); else *it = x;
        }
        return (int)target.size() - (int)tails.size();
    }
};
