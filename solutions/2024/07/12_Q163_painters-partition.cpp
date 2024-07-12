/*
 * Day: 163 | Date: 2024-07-12
 * Q163: Painter's Partition
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
    int minTime(vector<int>& boards, int painters) {
        auto ok = [&](int t) {
            int p = 1; long long cur = 0;
            for (int b : boards) {
                if (cur + b > t) { ++p; cur = 0; }
                cur += b;
            }
            return p <= painters;
        };
        int lo = *max_element(boards.begin(), boards.end());
        int hi = accumulate(boards.begin(), boards.end(), 0);
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (ok(mid)) hi = mid; else lo = mid + 1;
        }
        return lo;
    }
};
