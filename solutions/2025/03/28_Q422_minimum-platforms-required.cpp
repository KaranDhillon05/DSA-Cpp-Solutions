/*
 * Day: 422 | Date: 2025-03-28
 * Q422: Minimum Platforms Required
 * Difficulty: Medium
 * Pattern: Greedy
 * Section: 11 Greedy
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());
        int i = 0, j = 0, platforms = 0, best = 0;
        while (i < (int)arr.size()) {
            if (arr[i] <= dep[j]) { ++platforms; ++i; }
            else { --platforms; ++j; }
            best = max(best, platforms);
        }
        return best;
    }
};
