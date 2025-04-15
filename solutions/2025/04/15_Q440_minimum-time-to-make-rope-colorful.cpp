/*
 * Day: 440 | Date: 2025-04-15
 * Q440: Minimum Time to Make Rope Colorful
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
    int minCost(string colors, vector<int>& neededTime) {
        int res = 0;
        for (int i = 1; i < (int)colors.size(); ++i)
            if (colors[i] == colors[i - 1]) res += min(neededTime[i], neededTime[i - 1]);
        return res;
    }
};
