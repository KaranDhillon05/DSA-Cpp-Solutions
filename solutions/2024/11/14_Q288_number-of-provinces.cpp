/*
 * Day: 288 | Date: 2024-11-14
 * Q288: Number of Provinces
 * Difficulty: Medium
 * Pattern: Union-Find
 * Section: Graphs
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(), comps = 0;
        vector<int> vis(n);
        function<void(int)> dfs = [&](int u) {
            vis[u] = 1;
            for (int v = 0; v < n; ++v)
                if (isConnected[u][v] && !vis[v]) dfs(v);
        };
        for (int i = 0; i < n; ++i) if (!vis[i]) { ++comps; dfs(i); }
        return comps;
    }
};
