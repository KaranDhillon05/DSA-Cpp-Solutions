/*
 * Day: 285 | Date: 2024-11-11
 * Q285: Parallel Courses
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
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        vector<vector<int>> g(n + 1);
        vector<int> indeg(n + 1);
        for (auto& r : relations) { g[r[0]].push_back(r[1]); ++indeg[r[1]]; }
        queue<int> q;
        for (int i = 1; i <= n; ++i) if (!indeg[i]) q.push(i);
        int sem = 0, taken = 0;
        while (!q.empty()) {
            ++sem;
            int sz = q.size();
            while (sz--) {
                int u = q.front(); q.pop(); ++taken;
                for (int v : g[u]) if (--indeg[v] == 0) q.push(v);
            }
        }
        return taken == n ? sem : -1;
    }
};
