/*
 * Day: 272 | Date: 2024-10-29
 * Q272: Course Schedule
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
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g(numCourses);
        vector<int> indeg(numCourses);
        for (auto& e : prerequisites) {
            g[e[1]].push_back(e[0]);
            ++indeg[e[0]];
        }
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) if (!indeg[i]) q.push(i);
        int seen = 0;
        while (!q.empty()) {
            int u = q.front(); q.pop(); ++seen;
            for (int v : g[u]) if (--indeg[v] == 0) q.push(v);
        }
        return seen == numCourses;
    }
};
