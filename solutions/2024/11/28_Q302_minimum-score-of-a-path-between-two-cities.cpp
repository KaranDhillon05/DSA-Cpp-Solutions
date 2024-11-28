/*
 * Day: 302 | Date: 2024-11-28
 * Q302: Minimum Score of a Path Between Two Cities
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
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> g(n+1);
        for (auto& r:roads){ g[r[0]].push_back({r[1],r[2]}); g[r[1]].push_back({r[0],r[2]}); }
        vector<int> vis(n+1); queue<int> q; q.push(1); vis[1]=1; int score=INT_MAX;
        while(!q.empty()){
            int u=q.front(); q.pop();
            for (auto [v,w]:g[u]){ score=min(score,w); if(!vis[v]){ vis[v]=1; q.push(v);} }
        }
        return vis[n]?score:-1;
    }
};
