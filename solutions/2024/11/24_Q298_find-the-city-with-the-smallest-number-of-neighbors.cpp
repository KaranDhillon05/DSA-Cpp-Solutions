/*
 * Day: 298 | Date: 2024-11-24
 * Q298: Find the City with the Smallest Number of Neighbors
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
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        const int INF=1e9;
        vector<vector<int>> d(n, vector<int>(n,INF));
        for (int i=0;i<n;++i) d[i][i]=0;
        for (auto& e:edges) d[e[0]][e[1]]=d[e[1]][e[0]]=e[2];
        for (int k=0;k<n;++k) for (int i=0;i<n;++i) for (int j=0;j<n;++j)
            if(d[i][k]<INF&&d[k][j]<INF) d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
        int best=-1, mn=INF;
        for (int i=0;i<n;++i){ int c=0; for(int j=0;j<n;++j) if(d[i][j]<=distanceThreshold) ++c; if(c<=mn){mn=c;best=i;} }
        return best;
    }
};
