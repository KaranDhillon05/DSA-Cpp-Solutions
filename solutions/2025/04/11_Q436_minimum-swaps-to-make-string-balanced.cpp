/*
 * Day: 436 | Date: 2025-04-11
 * Q436: Minimum Swaps to Make String Balanced
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
    int minimumSwaps(string s) {
        int open = 0, swaps = 0;
        for (char c : s) {
            if (c == '[') ++open;
            else if (open > 0) --open;
            else ++swaps;
        }
        return swaps;
    }
};
