/*
 * Day: 297 | Date: 2024-11-23
 * Q297: Cheapest Flights Within K Stops
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
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        const int INF=1e9; vector<int> dist(n,INF); dist[src]=0;
        for (int i=0;i<=k;++i){
            vector<int> nd=dist;
            for (auto& f:flights) if(dist[f[0]]!=INF) nd[f[1]]=min(nd[f[1]],dist[f[0]]+f[2]);
            dist.swap(nd);
        }
        return dist[dst]>=INF?-1:dist[dst];
    }
};
