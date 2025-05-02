/*
 * Day: 457 | Date: 2025-05-02
 * Q457: Power of Two
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
    bool isPowerOfTwo(int n) { return n > 0 && (n & (n - 1)) == 0; }
};
