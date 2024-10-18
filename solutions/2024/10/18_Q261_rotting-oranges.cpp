/*
 * Day: 261 | Date: 2024-10-18
 * Q261: Rotting Oranges
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
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), fresh = 0;
        queue<pair<int,int>> q;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j] == 2) q.push({i,j});
                else if (grid[i][j] == 1) ++fresh;
        int dr[4] = {1,-1,0,0}, dc[4] = {0,0,1,-1}, mins = 0;
        while (!q.empty() && fresh) {
            int sz = q.size();
            while (sz--) {
                auto [r,c] = q.front(); q.pop();
                for (int k = 0; k < 4; ++k) {
                    int nr = r + dr[k], nc = c + dc[k];
                    if (nr >= 0 && nc >= 0 && nr < m && nc < n && grid[nr][nc] == 1) {
                        grid[nr][nc] = 2; --fresh; q.push({nr,nc});
                    }
                }
            }
            if (fresh) ++mins;
        }
        return fresh ? -1 : mins;
    }
};
