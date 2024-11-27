/*
 * Day: 301 | Date: 2024-11-27
 * Q301: Minimum Weighted Subgraph With the Required Paths
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
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        const long long INF=1e18;
        auto dijk=[&](int s){
            vector<long long> dist(n,INF);
            vector<vector<pair<int,int>>> g(n);
            for (auto& e:edges) g[e[0]].push_back({e[1],e[2]});
            priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;
            dist[s]=0; pq.push({0,s});
            while(!pq.empty()){
                auto [d,u]=pq.top(); pq.pop(); if(d>dist[u]) continue;
                for (auto [v,w]:g[u]) if(dist[v]>d+w){ dist[v]=d+w; pq.push({dist[v],v}); }
            }
            return dist;
        };
        auto d1=dijk(src1), d2=dijk(src2);
        vector<vector<pair<int,int>>> rg(n);
        for (auto& e:edges) rg[e[1]].push_back({e[0],e[2]});
        vector<long long> dt(n,INF);
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;
        dt[dest]=0; pq.push({0,dest});
        while(!pq.empty()){
            auto [d,u]=pq.top(); pq.pop(); if(d>dt[u]) continue;
            for (auto [v,w]:rg[u]) if(dt[v]>d+w){ dt[v]=d+w; pq.push({dt[v],v}); }
        }
        long long ans=INF;
        for (int m=0;m<n;++m) ans=min(ans,d1[m]+d2[m]+dt[m]);
        return ans>=INF?-1:ans;
    }
};
