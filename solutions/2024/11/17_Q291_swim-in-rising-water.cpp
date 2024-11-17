/*
 * Day: 291 | Date: 2024-11-17
 * Q291: Swim in Rising Water
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
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;
        pq.push({grid[0][0], 0, 0});
        vector<vector<int>> vis(n, vector<int>(n));
        int dr[4] = {1,-1,0,0}, dc[4] = {0,0,1,-1};
        while (!pq.empty()) {
            auto [t,r,c] = pq.top(); pq.pop();
            if (r==n-1 && c==n-1) return t;
            if (vis[r][c]) continue;
            vis[r][c]=1;
            for (int k=0;k<4;++k) {
                int nr=r+dr[k], nc=c+dc[k];
                if (nr>=0&&nc>=0&&nr<n&&nc<n&&!vis[nr][nc])
                    pq.push({max(t,grid[nr][nc]),nr,nc});
            }
        }
        return -1;
    }
};
