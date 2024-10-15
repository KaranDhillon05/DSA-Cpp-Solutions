/*
 * Day: 258 | Date: 2024-10-15
 * Q258: Flood Fill
 * Difficulty: Easy
 * Pattern: BFS
 * Section: Graphs
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size(), n = image[0].size(), orig = image[sr][sc];
        if (orig == color) return image;
        queue<pair<int,int>> q;
        q.push({sr, sc});
        image[sr][sc] = color;
        int dr[4] = {1,-1,0,0}, dc[4] = {0,0,1,-1};
        while (!q.empty()) {
            auto [r,c] = q.front(); q.pop();
            for (int k = 0; k < 4; ++k) {
                int nr = r + dr[k], nc = c + dc[k];
                if (nr >= 0 && nc >= 0 && nr < m && nc < n && image[nr][nc] == orig) {
                    image[nr][nc] = color;
                    q.push({nr, nc});
                }
            }
        }
        return image;
    }
};
