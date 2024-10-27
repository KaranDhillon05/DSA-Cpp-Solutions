/*
 * Day: 270 | Date: 2024-10-27
 * Q270: Cut Off Trees for Golf Event
 * Difficulty: Hard
 * Pattern: BFS
 * Section: Graphs
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int cutOffTree(vector<vector<int>>& forest) {
        vector<pair<int,int>> trees;
        for (int i = 0; i < (int)forest.size(); ++i)
            for (int j = 0; j < (int)forest[i].size(); ++j)
                if (forest[i][j] > 1) trees.push_back({forest[i][j], i * 1000 + j});
        sort(trees.begin(), trees.end());
        auto bfs = [&](pair<int,int> src, pair<int,int> dst) {
            if (src == dst) return 0;
            int m = forest.size(), n = forest[0].size();
            queue<pair<int,int>> q;
            q.push(src);
            vector<vector<int>> dist(m, vector<int>(n, -1));
            dist[src.first][src.second] = 0;
            int dr[4] = {1,-1,0,0}, dc[4] = {0,0,1,-1};
            while (!q.empty()) {
                auto [r,c] = q.front(); q.pop();
                for (int k = 0; k < 4; ++k) {
                    int nr = r + dr[k], nc = c + dc[k];
                    if (nr >= 0 && nc >= 0 && nr < m && nc < n && forest[nr][nc] && dist[nr][nc] == -1) {
                        dist[nr][nc] = dist[r][c] + 1;
                        if (make_pair(nr,nc) == dst) return dist[nr][nc];
                        q.push({nr, nc});
                    }
                }
            }
            return -1;
        };
        pair<int,int> cur = {0,0};
        int total = 0;
        for (auto& [h, key] : trees) {
            pair<int,int> nxt = {key/1000, key%1000};
            int d = bfs(cur, nxt);
            if (d < 0) return -1;
            total += d;
            cur = nxt;
        }
        return total;
    }
};
