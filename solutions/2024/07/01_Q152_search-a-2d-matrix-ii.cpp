/*
 * Day: 152 | Date: 2024-07-01
 * Q152: Search a 2D Matrix II
 * Difficulty: Medium
 * Pattern: Classic
 * Section: Binary Search
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = 0, c = (int)matrix[0].size() - 1;
        while (r < (int)matrix.size() && c >= 0) {
            if (matrix[r][c] == target) return true;
            if (matrix[r][c] > target) --c; else ++r;
        }
        return false;
    }
};
