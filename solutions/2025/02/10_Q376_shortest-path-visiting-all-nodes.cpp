/*
 * Day: 376 | Date: 2025-02-10
 * Q376: Shortest Path Visiting All Nodes
 * Difficulty: Hard
 * Pattern: Bitmask DP
 * Section: Dynamic Programming
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n=graph.size(), all=(1<<n)-1;
        queue<tuple<int,int,int>> q;
        vector<vector<int>> dist(n, vector<int>(1<<n, INT_MAX));
        for (int i=0;i<n;++i){ q.push({i,1<<i,0}); dist[i][1<<i]=0; }
        while(!q.empty()){
            auto [u,mask,d]=q.front(); q.pop();
            if (mask==all) return d;
            for (int v:graph[u]){
                int nmask=mask|(1<<v);
                if (d+1<dist[v][nmask]){ dist[v][nmask]=d+1; q.push({v,nmask,d+1}); }
            }
        }
        return 0;
    }
};
