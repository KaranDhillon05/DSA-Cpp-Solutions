/*
 * Day: 299 | Date: 2024-11-25
 * Q299: Path with Minimum Effort
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
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m=heights.size(), n=heights[0].size();
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;
        vector<vector<int>> dist(m, vector<int>(n,INT_MAX));
        pq.push({0,0,0}); int dr[4]={1,-1,0,0}, dc[4]={0,0,1,-1};
        while(!pq.empty()){
            auto [e,r,c]=pq.top(); pq.pop();
            if(r==m-1&&c==n-1) return e; if(e>=dist[r][c]) continue; dist[r][c]=e;
            for (int k=0;k<4;++k){
                int nr=r+dr[k], nc=c+dc[k];
                if(nr>=0&&nc>=0&&nr<m&&nc<n){
                    int ne=max(e,abs(heights[nr][nc]-heights[r][c]));
                    if(ne<dist[nr][nc]) pq.push({ne,nr,nc});
                }
            }
        }
        return 0;
    }
};
