/*
 * Day: 448 | Date: 2025-04-23
 * Q448: 4Sum II
 * Difficulty: Medium
 * Pattern: Hashing
 * Section: 12 Hashing & Math
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int,int> ab;
        for (int a : A) for (int b : B) ++ab[a + b];
        int res = 0;
        for (int c : C) for (int d : D) res += ab[-(c + d)];
        return res;
    }
};
