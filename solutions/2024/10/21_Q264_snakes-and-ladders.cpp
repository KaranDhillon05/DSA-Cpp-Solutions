/*
 * Day: 264 | Date: 2024-10-21
 * Q264: Snakes and Ladders
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
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        auto label = [&](int s) {
            int r = (s - 1) / n, c = (s - 1) % n;
            if (r % 2) c = n - 1 - c;
            return make_pair(n - 1 - r, c);
        };
        vector<int> dist(n*n + 1, -1);
        queue<int> q;
        q.push(1); dist[1] = 0;
        while (!q.empty()) {
            int s = q.front(); q.pop();
            if (s == n*n) return dist[s];
            for (int d = 1; d <= 6; ++d) {
                int ns = s + d;
                if (ns > n*n) break;
                auto [r,c] = label(ns);
                if (board[r][c] != -1) ns = board[r][c];
                if (dist[ns] == -1) { dist[ns] = dist[s] + 1; q.push(ns); }
            }
        }
        return -1;
    }
};
