/*
 * Day: 399 | Date: 2025-03-05
 * Q399: Count Numbers with Unique Digits
 * Difficulty: Medium
 * Pattern: Backtracking
 * Section: 10 Backtracking
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;
        if (n == 1) return 10;
        int res = 10, unique = 9, available = 9;
        for (int i = 2; i <= n && available > 0; ++i) {
            unique *= available--;
            res += unique;
        }
        return res;
    }
};
