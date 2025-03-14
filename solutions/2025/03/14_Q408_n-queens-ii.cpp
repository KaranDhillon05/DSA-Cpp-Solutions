/*
 * Day: 408 | Date: 2025-03-14
 * Q408: N-Queens II
 * Difficulty: Hard
 * Pattern: Backtracking
 * Section: 10 Backtracking
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
    int count = 0;
    bool valid(const vector<int>& cols, int row, int col) {
        for (int r = 0; r < row; ++r) {
            int c = cols[r];
            if (c == col || abs(c - col) == row - r) return false;
        }
        return true;
    }
    void dfs(int row, int n, vector<int>& cols) {
        if (row == n) { ++count; return; }
        for (int col = 0; col < n; ++col) {
            if (!valid(cols, row, col)) continue;
            cols[row] = col;
            dfs(row + 1, n, cols);
        }
    }
public:
    int totalNQueens(int n) {
        vector<int> cols(n);
        dfs(0, n, cols);
        return count;
    }
};
