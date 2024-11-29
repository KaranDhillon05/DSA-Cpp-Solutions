/*
 * Day: 303 | Date: 2024-11-29
 * Q303: Reachable Nodes In Subdivided Graph
 * Difficulty: Hard
 * Pattern: Shortest Path
 * Section: Graphs
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        vector<vector<pair<int,int>>> g(n);
        for (auto& e:edges){ g[e[0]].push_back({e[1],e[2]}); g[e[1]].push_back({e[0],e[2]}); }
        vector<int> dist(n,INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        dist[0]=0; pq.push({0,0});
        while(!pq.empty()){
            auto [d,u]=pq.top(); pq.pop(); if(d>dist[u]) continue;
            for (auto [v,w]:g[u]) if(dist[v]>d+w+1){ dist[v]=d+w+1; pq.push({dist[v],v}); }
        }
        int nodes=0; for(int i=0;i<n;++i) if(dist[i]<=maxMoves) ++nodes;
        for (auto& e:edges){
            int a=max(0,maxMoves-dist[e[0]]), b=max(0,maxMoves-dist[e[1]]);
            nodes+=min(e[2],a+b);
        }
        return nodes;
    }
};
