/*
 * Day: 430 | Date: 2025-04-05
 * Q430: Minimum Cost to Move Chips
 * Difficulty: Easy
 * Pattern: Greedy
 * Section: 11 Greedy
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int even = 0, odd = 0;
        for (int p : position) (p % 2 ? odd : even)++;
        return min(even, odd);
    }
};
