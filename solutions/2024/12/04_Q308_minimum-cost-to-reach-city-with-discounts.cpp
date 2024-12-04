/*
 * Day: 308 | Date: 2024-12-04
 * Q308: Minimum Cost to Reach City With Discounts
 * Difficulty: Medium
 * Pattern: Minimum Spanning Tree
 * Section: Graphs
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int n=passingFees.size(); const int INF=1e9;
        vector<vector<pair<int,int>>> g(n);
        for (auto& e:edges){ g[e[0]].push_back({e[1],e[2]}); g[e[1]].push_back({e[0],e[2]}); }
        vector<int> dist(n,INF), fee(n,INF);
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;
        pq.push({0,passingFees[0],0}); dist[0]=0; fee[0]=passingFees[0];
        while(!pq.empty()){
            auto [t,c,u]=pq.top(); pq.pop(); if(u==n-1) return c;
            if(t>dist[u]||(t==dist[u]&&c>fee[u])) continue;
            for (auto [v,w]:g[u]){
                int nt=t+w, nc=c+passingFees[v];
                if(nt<=maxTime&&(nt<dist[v]||(nt==dist[v]&&nc<fee[v]))){ dist[v]=nt; fee[v]=nc; pq.push({nt,nc,v}); }
            }
        }
        return -1;
    }
};
