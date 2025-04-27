/*
 * Day: 452 | Date: 2025-04-27
 * Q452: Brick Wall
 * Difficulty: Medium
 * Pattern: Hashing
 * Section: 12 Hashing & Math
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int,int> gap;
        int maxGap = 0;
        for (auto& row : wall) {
            int prefix = 0;
            for (int i = 0; i + 1 < (int)row.size(); ++i) {
                prefix += row[i];
                maxGap = max(maxGap, ++gap[prefix]);
            }
        }
        return wall.size() - maxGap;
    }
};
