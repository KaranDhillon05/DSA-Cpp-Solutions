/*
 * Day: 161 | Date: 2024-07-10
 * Q161: Allocate Minimum Number of Pages
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
    int findPages(vector<int>& arr, int k) {
        auto ok = [&](int mx) {
            int students = 1, cur = 0;
            for (int p : arr) {
                if (cur + p > mx) { ++students; cur = 0; }
                cur += p;
            }
            return students <= k;
        };
        int lo = *max_element(arr.begin(), arr.end());
        int hi = accumulate(arr.begin(), arr.end(), 0);
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (ok(mid)) hi = mid; else lo = mid + 1;
        }
        return lo;
    }
};
