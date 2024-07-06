/*
 * Day: 157 | Date: 2024-07-06
 * Q157: Koko Eating Bananas
 * Difficulty: Medium
 * Pattern: Parametric
 * Section: Binary Search
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        auto ok = [&](int speed) {
            long long hrs = 0;
            for (int p : piles) hrs += (p + speed - 1) / speed;
            return hrs <= h;
        };
        int lo = 1, hi = *max_element(piles.begin(), piles.end());
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (ok(mid)) hi = mid; else lo = mid + 1;
        }
        return lo;
    }
};
