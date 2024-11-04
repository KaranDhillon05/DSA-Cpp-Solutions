/*
 * Day: 278 | Date: 2024-11-04
 * Q278: All Paths from Source to Target
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
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        vector<int> path = {0};
        function<void(int)> dfs = [&](int u) {
            if (u == (int)graph.size() - 1) { res.push_back(path); return; }
            for (int v : graph[u]) { path.push_back(v); dfs(v); path.pop_back(); }
        };
        dfs(0);
        return res;
    }
};
