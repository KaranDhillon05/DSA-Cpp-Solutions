/*
 * Day: 169 | Date: 2024-07-18
 * Q169: Maximum Running Time of N Computers
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
    long long maxRunTime(int n, vector<int>& batteries) {
        long long lo = 0, hi = 0;
        for (int b : batteries) hi += b;
        auto ok = [&](long long t) {
            long long need = 0;
            for (int b : batteries) need += min<long long>(b, t);
            return need >= (long long)n * t;
        };
        while (lo < hi) {
            long long mid = lo + (hi - lo + 1) / 2;
            if (ok(mid)) lo = mid; else hi = mid - 1;
        }
        return lo;
    }
};
