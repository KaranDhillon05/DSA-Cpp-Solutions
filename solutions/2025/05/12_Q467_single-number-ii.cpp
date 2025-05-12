/*
 * Day: 467 | Date: 2025-05-12
 * Q467: Single Number II
 * Difficulty: Medium
 * Pattern: Bits
 * Section: 12 Hashing & Math
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0, twos = 0;
        for (int x : nums) {
            ones = (ones ^ x) & ~twos;
            twos = (twos ^ x) & ~ones;
        }
        return ones;
    }
};
