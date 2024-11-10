/*
 * Day: 284 | Date: 2024-11-10
 * Q284: Find Eventual Safe States
 * Difficulty: Medium
 * Pattern: Topological Sort
 * Section: Graphs
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n);
        function<bool(int)> dfs = [&](int u) {
            if (color[u] == 1) return false;
            if (color[u] == 2) return true;
            color[u] = 1;
            for (int v : graph[u]) if (!dfs(v)) return false;
            color[u] = 2;
            return true;
        };
        vector<int> safe;
        for (int i = 0; i < n; ++i) if (dfs(i)) safe.push_back(i);
        return safe;
    }
};
