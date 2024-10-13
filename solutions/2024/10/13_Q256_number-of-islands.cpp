/*
 * Day: 256 | Date: 2024-10-13
 * Q256: Number of Islands
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
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size(), cnt = 0;
        function<void(int,int)> dfs = [&](int r, int c) {
            if (r < 0 || c < 0 || r >= m || c >= n || grid[r][c] != '1') return;
            grid[r][c] = '0';
            dfs(r+1,c); dfs(r-1,c); dfs(r,c+1); dfs(r,c-1);
        };
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j] == '1') { ++cnt; dfs(i,j); }
        return cnt;
    }
};
