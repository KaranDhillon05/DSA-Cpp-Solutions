/*
 * Day: 164 | Date: 2024-07-13
 * Q164: EKO - Cutting Trees
 * Difficulty: Hard
 * Pattern: Parametric
 * Section: Binary Search
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long cutWood(vector<int>& trees, long long needed) {
        auto wood = [&](long long h) {
            long long w = 0;
            for (int t : trees) if (t > h) w += t - h;
            return w;
        };
        long long lo = 0, hi = *max_element(trees.begin(), trees.end());
        while (lo < hi) {
            long long mid = lo + (hi - lo + 1) / 2;
            if (wood(mid) >= needed) lo = mid; else hi = mid - 1;
        }
        return lo;
    }
};
