/*
 * Day: 417 | Date: 2025-03-23
 * Q417: Tiling a Rectangle with the Fewest Squares
 * Difficulty: Hard
 * Pattern: Backtracking
 * Section: 10 Backtracking
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
    int best = INT_MAX;
    void dfs(int n, int m, int h, int w, int cnt) {
        if (h == n) { best = min(best, cnt); return; }
        if (cnt >= best) return;
        int rw = w;
        while (rw <= m && h + rw <= n) {
            int rh = rw;
            while (rh <= rw && h + rh <= n) {
                dfs(n, m, h + rh, rw - rh, cnt + 1);
                ++rh;
            }
            ++rw;
        }
    }
public:
    int tilingRectangle(int n, int m) {
        best = INT_MAX;
        dfs(n, m, 0, m, 0);
        return best;
    }
};
