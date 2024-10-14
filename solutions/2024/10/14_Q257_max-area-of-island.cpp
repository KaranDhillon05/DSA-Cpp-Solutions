/*
 * Day: 257 | Date: 2024-10-14
 * Q257: Max Area of Island
 * Difficulty: Medium
 * Pattern: BFS
 * Section: Graphs
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), best = 0;
        function<int(int,int)> dfs = [&](int r, int c) {
            if (r < 0 || c < 0 || r >= m || c >= n || grid[r][c] == 0) return 0;
            grid[r][c] = 0;
            return 1 + dfs(r+1,c) + dfs(r-1,c) + dfs(r,c+1) + dfs(r,c-1);
        };
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j]) best = max(best, dfs(i,j));
        return best;
    }
};
