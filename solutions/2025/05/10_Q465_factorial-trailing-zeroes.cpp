/*
 * Day: 465 | Date: 2025-05-10
 * Q465: Factorial Trailing Zeroes
 * Difficulty: Medium
 * Pattern: Math
 * Section: 12 Hashing & Math
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        int res = 0;
        for (long long p = 5; p <= n; p *= 5) res += n / p;
        return res;
    }
};
