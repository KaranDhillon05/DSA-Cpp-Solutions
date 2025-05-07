/*
 * Day: 462 | Date: 2025-05-07
 * Q462: Ugly Number
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
    bool isUgly(int n) {
        if (n <= 0) return false;
        for (int p : {2, 3, 5})
            while (n % p == 0) n /= p;
        return n == 1;
    }
};
