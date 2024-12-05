/*
 * Day: 309 | Date: 2024-12-05
 * Q309: Find Critical and Pseudo-Critical Edges in Minimum Spanning Tree
 * Difficulty: Hard
 * Pattern: Minimum Spanning Tree
 * Section: Graphs
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        for (int i=0;i<(int)edges.size();++i) edges[i].push_back(i);
        auto sorted=edges;
        sort(sorted.begin(), sorted.end(), [](auto& a, auto& b){ return a[2]<b[2]; });
        auto mst=[&](function<bool(int)> use){
            vector<int> p(n); iota(p.begin(), p.end(), 0);
            function<int(int)> f=[&](int x){ return p[x]==x?x:p[x]=f(p[x]); };
            int w=0,c=0;
            for (auto& e:sorted){ if(!use(e[3])) continue; int a=f(e[0]), b=f(e[1]); if(a!=b){ p[b]=a; w+=e[2]; ++c; } }
            return c==n-1?w:-1;
        };
        int base=mst([](int){ return true; });
        vector<int> crit, pseudo;
        for (auto& e:edges){
            int idx=e[3];
            if(mst([&](int i){ return i!=idx; })>base) crit.push_back(idx);
            else if(mst([&](int i){ return i==idx; })==base) pseudo.push_back(idx);
        }
        return {crit,pseudo};
    }
};
