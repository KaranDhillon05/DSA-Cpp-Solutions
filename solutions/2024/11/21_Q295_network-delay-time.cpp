/*
 * Day: 295 | Date: 2024-11-21
 * Q295: Network Delay Time
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
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        const int INF=1e9;
        vector<vector<pair<int,int>>> g(n+1);
        for (auto& t:times) g[t[0]].push_back({t[1],t[2]});
        vector<int> dist(n+1,INF);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        dist[k]=0; pq.push({0,k});
        while(!pq.empty()){
            auto [d,u]=pq.top(); pq.pop(); if(d>dist[u]) continue;
            for (auto [v,w]:g[u]) if(dist[v]>d+w){ dist[v]=d+w; pq.push({dist[v],v}); }
        }
        int ans=0; for(int i=1;i<=n;++i) ans=max(ans,dist[i]);
        return ans>=INF?-1:ans;
    }
};
