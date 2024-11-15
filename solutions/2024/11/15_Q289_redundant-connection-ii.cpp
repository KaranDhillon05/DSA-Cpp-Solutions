/*
 * Day: 289 | Date: 2024-11-15
 * Q289: Redundant Connection II
 * Difficulty: Hard
 * Pattern: Union-Find
 * Section: Graphs
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n + 1), candA, candB;
        function<int(int)> find = [&](int x) {
            return parent[x] == x ? x : parent[x] = find(parent[x]);
        };
        for (auto& e : edges) {
            if (parent[e[1]]) { candA = parent[e[1]] == e[1] ? e : vector<int>{parent[e[1]], e[1]}; candB = e; }
            else parent[e[1]] = e[0];
        }
        function<bool(vector<int>)> hasCycle = [&](vector<int> skip) {
            fill(parent.begin(), parent.end(), 0);
            for (auto& e : edges) {
                if (e == skip) continue;
                if (parent[e[1]]) return true;
                parent[e[1]] = e[0];
            }
            return false;
        };
        if (candA.empty()) {
            int nn = edges.size();
            vector<int> parent(nn + 1);
            iota(parent.begin(), parent.end(), 0);
            function<int(int)> find2 = [&](int x) {
                return parent[x] == x ? x : parent[x] = find2(parent[x]);
            };
            for (auto& e : edges) {
                int a = find2(e[0]), b = find2(e[1]);
                if (a == b) return e;
                parent[b] = a;
            }
            return {};
        }
        if (!hasCycle(candB)) return candB;
        return candA;
    }
};
