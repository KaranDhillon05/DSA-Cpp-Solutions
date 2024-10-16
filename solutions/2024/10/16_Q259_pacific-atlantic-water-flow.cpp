/*
 * Day: 259 | Date: 2024-10-16
 * Q259: Pacific Atlantic Water Flow
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
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<int>> pac(m, vector<int>(n)), atl(m, vector<int>(n));
        function<void(int,int,vector<vector<int>>&)> dfs = [&](int r, int c, auto& reach) {
            reach[r][c] = 1;
            int dr[4] = {1,-1,0,0}, dc[4] = {0,0,1,-1};
            for (int k = 0; k < 4; ++k) {
                int nr = r + dr[k], nc = c + dc[k];
                if (nr >= 0 && nc >= 0 && nr < m && nc < n && !reach[nr][nc] && heights[nr][nc] >= heights[r][c])
                    dfs(nr, nc, reach);
            }
        };
        for (int i = 0; i < m; ++i) { dfs(i,0,pac); dfs(i,n-1,atl); }
        for (int j = 0; j < n; ++j) { dfs(0,j,pac); dfs(m-1,j,atl); }
        vector<vector<int>> res;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (pac[i][j] && atl[i][j]) res.push_back({i,j});
        return res;
    }
};
