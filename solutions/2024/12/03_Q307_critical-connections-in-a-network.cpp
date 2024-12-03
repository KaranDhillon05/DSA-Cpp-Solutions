/*
 * Day: 307 | Date: 2024-12-03
 * Q307: Critical Connections in a Network
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
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> g(n); for (auto& e:connections){ g[e[0]].push_back(e[1]); g[e[1]].push_back(e[0]); }
        vector<int> disc(n,-1), low(n); vector<vector<int>> res; int timer=0;
        function<void(int,int)> dfs=[&](int u,int p){
            disc[u]=low[u]=timer++;
            for (int v:g[u]){
                if(v==p) continue;
                if(disc[v]==-1){ dfs(v,u); low[u]=min(low[u],low[v]); if(low[v]>disc[u]) res.push_back({u,v}); }
                else low[u]=min(low[u],disc[v]);
            }
        };
        dfs(0,-1); return res;
    }
};
