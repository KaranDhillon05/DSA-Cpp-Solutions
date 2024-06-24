/*
 * Day: 145 | Date: 2024-06-24
 * Q145: Rotting Oranges
 * Difficulty: Medium
 * Pattern: Queue/Deque
 * Section: Stacks & Queues
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), fresh = 0, ans = 0;
        queue<pair<int,int>> q;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j] == 2) q.push({i, j});
                else if (grid[i][j] == 1) ++fresh;
        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        while (!q.empty() && fresh) {
            int sz = q.size();
            while (sz--) {
                auto [i, j] = q.front(); q.pop();
                for (auto& d : dirs) {
                    int ni = i + d[0], nj = j + d[1];
                    if (ni >= 0 && ni < m && nj >= 0 && nj < n && grid[ni][nj] == 1) {
                        grid[ni][nj] = 2; --fresh; q.push({ni, nj});
                    }
                }
            }
            ++ans;
        }
        return fresh ? -1 : max(0, ans - 1);
    }
};
