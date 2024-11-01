/*
 * Day: 275 | Date: 2024-11-01
 * Q275: Graph Valid Tree
 * Difficulty: Medium
 * Pattern: DFS
 * Section: Graphs
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if ((int)edges.size() != n - 1) return false;
        vector<vector<int>> g(n);
        for (auto& e : edges) { g[e[0]].push_back(e[1]); g[e[1]].push_back(e[0]); }
        vector<int> vis(n);
        function<bool(int,int)> dfs = [&](int u, int p) {
            vis[u] = 1;
            for (int v : g[u]) {
                if (v == p) continue;
                if (vis[v]) return false;
                if (!dfs(v, u)) return false;
            }
            return true;
        };
        return dfs(0, -1);
    }
};
