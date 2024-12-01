/*
 * Day: 305 | Date: 2024-12-01
 * Q305: Min Cost to Connect All Points
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
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size(); vector<int> dist(n,INT_MAX), vis(n);
        auto man=[&](int i,int j){ return abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]); };
        dist[0]=0; int total=0;
        for (int it=0; it<n; ++it){
            int u=-1; for(int i=0;i<n;++i) if(!vis[i]&&(u==-1||dist[i]<dist[u])) u=i;
            vis[u]=1; total+=dist[u];
            for (int v=0; v<n; ++v) if(!vis[v]) dist[v]=min(dist[v],man(u,v));
        }
        return total;
    }
};
