/*
 * Day: 459 | Date: 2025-05-04
 * Q459: Power of Four
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
    bool isPowerOfFour(int n) { return n > 0 && (n & (n - 1)) == 0 && n % 3 == 1; }
};
