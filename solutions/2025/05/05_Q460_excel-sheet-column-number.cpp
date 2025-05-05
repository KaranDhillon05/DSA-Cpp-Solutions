/*
 * Day: 460 | Date: 2025-05-05
 * Q460: Excel Sheet Column Number
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
    int titleToNumber(string columnTitle) {
        int res = 0;
        for (char c : columnTitle) res = res * 26 + (c - 'A' + 1);
        return res;
    }
};
