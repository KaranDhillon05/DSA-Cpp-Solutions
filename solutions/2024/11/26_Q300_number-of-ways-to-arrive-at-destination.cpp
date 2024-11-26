/*
 * Day: 300 | Date: 2024-11-26
 * Q300: Number of Ways to Arrive at Destination
 * Difficulty: Medium
 * Pattern: Shortest Path
 * Section: Graphs
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const long long MOD=1e9+7, INF=1e18;
        vector<vector<pair<int,int>>> g(n);
        for (auto& r:roads){ g[r[0]].push_back({r[1],r[2]}); g[r[1]].push_back({r[0],r[2]}); }
        vector<long long> dist(n,INF), ways(n); ways[0]=1;
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;
        pq.push({0,0});
        while(!pq.empty()){
            auto [d,u]=pq.top(); pq.pop(); if(d>dist[u]) continue;
            for (auto [v,w]:g[u]){
                long long nd=d+w;
                if(nd<dist[v]){ dist[v]=nd; ways[v]=ways[u]; pq.push({nd,v}); }
                else if(nd==dist[v]) ways[v]=(ways[v]+ways[u])%MOD;
            }
        }
        return (int)ways[n-1];
    }
};
