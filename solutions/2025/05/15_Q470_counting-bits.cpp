/*
 * Day: 470 | Date: 2025-05-15
 * Q470: Counting Bits
 * Difficulty: Easy
 * Pattern: Bits
 * Section: 12 Hashing & Math
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n + 1);
        for (int i = 1; i <= n; ++i) res[i] = res[i >> 1] + (i & 1);
        return res;
    }
};
