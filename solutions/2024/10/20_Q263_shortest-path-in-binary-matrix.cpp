/*
 * Day: 263 | Date: 2024-10-20
 * Q263: Shortest Path in Binary Matrix
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
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] || grid[n-1][n-1]) return -1;
        queue<pair<int,int>> q;
        q.push({0,0});
        grid[0][0] = 1;
        int dr[8] = {1,-1,0,0,1,1,-1,-1}, dc[8] = {0,0,1,-1,1,-1,1,-1};
        for (int dist = 1; !q.empty(); ++dist) {
            int sz = q.size();
            while (sz--) {
                auto [r,c] = q.front(); q.pop();
                if (r == n-1 && c == n-1) return dist;
                for (int k = 0; k < 8; ++k) {
                    int nr = r + dr[k], nc = c + dc[k];
                    if (nr >= 0 && nc >= 0 && nr < n && nc < n && !grid[nr][nc]) {
                        grid[nr][nc] = 1;
                        q.push({nr, nc});
                    }
                }
            }
        }
        return -1;
    }
};
