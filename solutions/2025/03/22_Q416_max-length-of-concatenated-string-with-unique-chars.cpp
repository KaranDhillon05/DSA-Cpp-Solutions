/*
 * Day: 416 | Date: 2025-03-22
 * Q416: Max Length of Concatenated String with Unique Chars
 * Difficulty: Medium
 * Pattern: Backtracking
 * Section: 10 Backtracking
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
    int best = 0;
    void dfs(const vector<string>& arr, int i, int mask) {
        if (i == (int)arr.size()) { best = max(best, __builtin_popcount(mask)); return; }
        dfs(arr, i + 1, mask);
        int m = mask;
        for (char c : arr[i]) {
            int bit = 1 << (c - 'a');
            if (mask & bit) return;
            mask |= bit;
        }
        dfs(arr, i + 1, mask);
    }
public:
    int maxLength(vector<string>& arr) {
        dfs(arr, 0, 0);
        return best;
    }
};
