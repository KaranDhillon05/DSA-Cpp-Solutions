/*
 * Day: 294 | Date: 2024-11-20
 * Q294: Remove Max Number of Edges to Keep Graph Fully Traversable
 * Difficulty: Hard
 * Pattern: Union-Find
 * Section: Graphs
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        vector<int> a(n+1), b(n+1); iota(a.begin(), a.end(), 0); iota(b.begin(), b.end(), 0);
        function<int(vector<int>&,int)> f = [&](vector<int>& p,int x){ return p[x]==x?x:p[x]=f(p,p[x]); };
        auto u = [&](vector<int>& p,int x,int y){ x=f(p,x); y=f(p,y); if(x==y) return false; p[y]=x; return true; };
        sort(edges.begin(), edges.end(), [](auto& x, auto& y){ return x[0]>y[0]; });
        int kept=0;
        for (auto& e:edges){
            if(e[0]==3){ bool ua=u(a,e[1],e[2]), ub=u(b,e[1],e[2]); if(ua||ub) ++kept; }
            else if(e[0]==1){ if(u(a,e[1],e[2])) ++kept; }
            else if(u(b,e[1],e[2])) ++kept;
        }
        return (int)edges.size()-kept;
    }
};
