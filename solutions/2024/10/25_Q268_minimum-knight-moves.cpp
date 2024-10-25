/*
 * Day: 268 | Date: 2024-10-25
 * Q268: Minimum Knight Moves
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
    int minKnightMoves(int x, int y) {
        x = abs(x); y = abs(y);
        queue<pair<int,int>> q;
        q.push({0,0});
        unordered_set<long long> seen;
        auto key = [](int a, int b){ return ((long long)a << 32) ^ (unsigned)b; };
        seen.insert(key(0,0));
        int dr[8] = {2,2,-2,-2,1,1,-1,-1}, dc[8] = {1,-1,1,-1,2,-2,2,-2};
        for (int dist = 0; !q.empty(); ++dist) {
            int sz = q.size();
            while (sz--) {
                auto [r,c] = q.front(); q.pop();
                if (r == x && c == y) return dist;
                for (int k = 0; k < 8; ++k) {
                    int nr = r + dr[k], nc = c + dc[k];
                    long long k2 = key(nr, nc);
                    if (nr >= -1 && nc >= -1 && !seen.count(k2)) {
                        seen.insert(k2);
                        q.push({nr, nc});
                    }
                }
            }
        }
        return -1;
    }
};
