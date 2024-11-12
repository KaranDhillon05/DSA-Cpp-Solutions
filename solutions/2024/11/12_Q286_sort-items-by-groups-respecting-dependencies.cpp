/*
 * Day: 286 | Date: 2024-11-12
 * Q286: Sort Items by Groups Respecting Dependencies
 * Difficulty: Hard
 * Pattern: Topological Sort
 * Section: Graphs
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortItems(int n, vector<int>& group, vector<vector<int>>& beforeItems) {
        for (int i = 0; i < n; ++i) if (group[i] == -1) group[i] = n++;
        int G = *max_element(group.begin(), group.end()) + 1;
        vector<vector<int>> itemG(n), groupG(G);
        vector<int> itemIndeg(n), groupIndeg(G);
        for (int i = 0; i < n; ++i)
            for (int p : beforeItems[i]) {
                itemG[p].push_back(i); ++itemIndeg[i];
                if (group[p] != group[i]) { groupG[group[p]].push_back(group[i]); ++groupIndeg[group[i]]; }
            }
        auto topo = [](vector<vector<int>>& g, vector<int>& indeg) {
            queue<int> q;
            vector<int> order;
            for (int i = 0; i < (int)g.size(); ++i) if (!indeg[i]) q.push(i);
            while (!q.empty()) {
                int u = q.front(); q.pop();
                order.push_back(u);
                for (int v : g[u]) if (--indeg[v] == 0) q.push(v);
            }
            return (int)order.size() == (int)g.size() ? order : vector<int>{};
        };
        vector<int> gOrder = topo(groupG, groupIndeg);
        if (gOrder.empty()) return {};
        vector<int> res;
        for (int g : gOrder) {
            vector<vector<int>> sub(n);
            vector<int> subIndeg(n);
            for (int i = 0; i < n; ++i) if (group[i] == g)
                for (int v : itemG[i]) if (group[v] == g) { sub[i].push_back(v); ++subIndeg[v]; }
            vector<int> itemOrder = topo(sub, subIndeg);
            if (itemOrder.empty()) return {};
            for (int id : itemOrder) if (group[id] == g) res.push_back(id);
        }
        return res;
    }
};
