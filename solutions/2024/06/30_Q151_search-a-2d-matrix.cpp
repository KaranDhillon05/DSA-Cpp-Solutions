/*
 * Day: 151 | Date: 2024-06-30
 * Q151: Search a 2D Matrix
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
        int m = matrix.size(), n = matrix[0].size();
        int lo = 0, hi = m * n - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2, r = mid / n, c = mid % n;
            if (matrix[r][c] == target) return true;
            if (matrix[r][c] < target) lo = mid + 1; else hi = mid - 1;
        }
        return false;
    }
};
