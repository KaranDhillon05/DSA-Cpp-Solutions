/*
 * Day: 274 | Date: 2024-10-31
 * Q274: Number of Connected Components in an Undirected Graph
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
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> parent(n), rankv(n, 0);
        iota(parent.begin(), parent.end(), 0);
        function<int(int)> find = [&](int x) {
            return parent[x] == x ? x : parent[x] = find(parent[x]);
        };
        int comps = n;
        for (auto& e : edges) {
            int a = find(e[0]), b = find(e[1]);
            if (a != b) {
                if (rankv[a] < rankv[b]) swap(a, b);
                parent[b] = a;
                if (rankv[a] == rankv[b]) ++rankv[a];
                --comps;
            }
        }
        return comps;
    }
};
