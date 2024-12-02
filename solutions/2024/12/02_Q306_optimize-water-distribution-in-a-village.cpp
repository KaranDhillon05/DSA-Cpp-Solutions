/*
 * Day: 306 | Date: 2024-12-02
 * Q306: Optimize Water Distribution in a Village
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
    int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
        vector<vector<pair<int,int>>> g(n+1);
        for (int i=0;i<n;++i) g[0].push_back({i+1,wells[i]});
        for (auto& p:pipes){ g[p[0]].push_back({p[1],p[2]}); g[p[1]].push_back({p[0],p[2]}); }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        pq.push({0,0}); vector<int> vis(n+1); int cost=0;
        while(!pq.empty()){
            auto [c,u]=pq.top(); pq.pop(); if(vis[u]) continue; vis[u]=1; cost+=c;
            for (auto [v,w]:g[u]) if(!vis[v]) pq.push({w,v});
        }
        return cost;
    }
};
