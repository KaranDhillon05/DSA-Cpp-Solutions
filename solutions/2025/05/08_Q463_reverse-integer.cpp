/*
 * Day: 463 | Date: 2025-05-08
 * Q463: Reverse Integer
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
    int reverse(int x) {
        long long res = 0;
        while (x) {
            res = res * 10 + x % 10;
            x /= 10;
        }
        return (res < INT_MIN || res > INT_MAX) ? 0 : (int)res;
    }
};
