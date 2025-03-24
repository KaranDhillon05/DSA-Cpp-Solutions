/*
 * Day: 418 | Date: 2025-03-24
 * Q418: Coloring a Border
 * Difficulty: Medium
 * Pattern: Backtracking
 * Section: 10 Backtracking
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
    int m, n;
    vector<vector<int>> g;
    void paint(int r, int c, int color, int border) {
        if (r < 0 || c < 0 || r >= m || c >= n || g[r][c] != color) return;
        g[r][c] = border;
        paint(r + 1, c, color, border);
        paint(r - 1, c, color, border);
        paint(r, c + 1, color, border);
        paint(r, c - 1, color, border);
    }
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        g = grid;
        m = grid.size();
        n = grid[0].size();
        int orig = g[row][col];
        paint(row, col, orig, -orig);
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) {
                if (g[i][j] == -orig) {
                    bool border = i == 0 || j == 0 || i == m - 1 || j == n - 1
                               || (i > 0 && abs(g[i - 1][j]) != orig)
                               || (i < m - 1 && abs(g[i + 1][j]) != orig)
                               || (j > 0 && abs(g[i][j - 1]) != orig)
                               || (j < n - 1 && abs(g[i][j + 1]) != orig);
                    g[i][j] = border ? color : orig;
                } else if (g[i][j] < 0) {
                    g[i][j] = orig;
                }
            }
        return g;
    }
};
