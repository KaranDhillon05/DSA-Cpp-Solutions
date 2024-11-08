/*
 * Day: 282 | Date: 2024-11-08
 * Q282: Sequence Reconstruction
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
    bool sequenceReconstruction(vector<int>& nums, vector<vector<int>>& sequences) {
        int n = nums.size();
        vector<vector<int>> g(n + 1);
        vector<int> indeg(n + 1);
        for (auto& seq : sequences)
            for (int i = 0; i + 1 < (int)seq.size(); ++i) {
                if (!g[seq[i]].count(seq[i+1])) {
                    g[seq[i]].insert(seq[i+1]);
                    ++indeg[seq[i+1]];
                }
            }
        queue<int> q;
        for (int i = 1; i <= n; ++i) if (!indeg[i]) q.push(i);
        while (!q.empty()) {
            if ((int)q.size() > 1) return false;
            int u = q.front(); q.pop();
            for (int v : g[u]) if (--indeg[v] == 0) q.push(v);
        }
        return true;
    }
};
