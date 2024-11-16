/*
 * Day: 290 | Date: 2024-11-16
 * Q290: Making a Large Island
 * Difficulty: Hard
 * Pattern: Union-Find
 * Section: Graphs
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size(), idx = 2, best = 0;
        vector<int> area(n*n + 2);
        int dr[4] = {1,-1,0,0}, dc[4] = {0,0,1,-1};
        function<int(int,int)> dfs = [&](int r, int c) {
            grid[r][c] = idx;
            int sz = 1;
            for (int k = 0; k < 4; ++k) {
                int nr = r + dr[k], nc = c + dc[k];
                if (nr >= 0 && nc >= 0 && nr < n && nc < n && grid[nr][nc] == 1)
                    sz += dfs(nr, nc);
            }
            return sz;
        };
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j] == 1) area[idx] = dfs(i, j), best = max(best, area[idx++]);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j] == 0) {
                    unordered_set<int> seen;
                    int total = 1;
                    for (int k = 0; k < 4; ++k) {
                        int nr = i + dr[k], nc = j + dc[k];
                        if (nr >= 0 && nc >= 0 && nr < n && nc < n && grid[nr][nc] > 1 && !seen.count(grid[nr][nc]))
                            seen.insert(grid[nr][nc]), total += area[grid[nr][nc]];
                    }
                    best = max(best, total);
                }
        return best;
    }
};
