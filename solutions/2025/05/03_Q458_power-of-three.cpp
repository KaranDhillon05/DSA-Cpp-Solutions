/*
 * Day: 458 | Date: 2025-05-03
 * Q458: Power of Three
 * Difficulty: Easy
 * Pattern: Math
 * Section: 12 Hashing & Math
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
        while (n > 1 && n % 3 == 0) n /= 3;
        return n == 1;
    }
};
