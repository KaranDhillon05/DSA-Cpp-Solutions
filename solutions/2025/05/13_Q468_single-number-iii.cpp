/*
 * Day: 468 | Date: 2025-05-13
 * Q468: Single Number III
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
    vector<int> singleNumber(vector<int>& nums) {
        long long xorAll = 0;
        for (int x : nums) xorAll ^= x;
        long long diff = xorAll & -xorAll;
        int a = 0, b = 0;
        for (int x : nums) (x & diff ? a : b) ^= x;
        return {a, b};
    }
};
