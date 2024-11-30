/*
 * Day: 304 | Date: 2024-11-30
 * Q304: K-th Shortest Path
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
    int kthShortestPath(int n, vector<vector<int>>& edges, int src, int dst, int k) {
        vector<vector<pair<int,int>>> g(n);
        for (auto& e:edges) g[e[0]].push_back({e[1],e[2]});
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        pq.push({0,src}); vector<int> cnt(n);
        while(!pq.empty()){
            auto [d,u]=pq.top(); pq.pop();
            if(u==dst){ if(++cnt[u]==k) return d; } else ++cnt[u];
            if(cnt[u]>k) continue;
            for (auto [v,w]:g[u]) pq.push({d+w,v});
        }
        return -1;
    }
};
