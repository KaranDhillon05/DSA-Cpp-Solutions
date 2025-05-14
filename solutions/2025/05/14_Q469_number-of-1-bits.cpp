/*
 * Day: 469 | Date: 2025-05-14
 * Q469: Number of 1 Bits
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
    int hammingWeight(uint32_t n) { return __builtin_popcount(n); }
};
