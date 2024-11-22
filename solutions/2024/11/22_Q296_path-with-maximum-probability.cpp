/*
 * Day: 296 | Date: 2024-11-22
 * Q296: Path with Maximum Probability
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
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int,double>>> g(n);
        for (int i=0;i<(int)edges.size();++i){
            g[edges[i][0]].push_back({edges[i][1],succProb[i]});
            g[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        vector<double> prob(n,0); priority_queue<pair<double,int>> pq;
        prob[start]=1; pq.push({1,start});
        while(!pq.empty()){
            auto [p,u]=pq.top(); pq.pop(); if(p<prob[u]) continue;
            for (auto [v,w]:g[u]) if(prob[v]<p*w){ prob[v]=p*w; pq.push({prob[v],v}); }
        }
        return prob[end];
    }
};
