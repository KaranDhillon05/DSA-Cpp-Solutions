/*
 * Day: 292 | Date: 2024-11-18
 * Q292: Earliest Moment When Everyone Become Friends
 * Difficulty: Medium
 * Pattern: Union-Find
 * Section: Graphs
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int earliestAcq(vector<vector<int>>& logs, int n) {
        sort(logs.begin(), logs.end());
        vector<int> p(n); iota(p.begin(), p.end(), 0);
        function<int(int)> f = [&](int x){ return p[x]==x?x:p[x]=f(p[x]); };
        int c=n;
        for (auto& L:logs){ int a=f(L[1]),b=f(L[2]); if(a!=b){p[b]=a; if(--c==1) return L[0];} }
        return -1;
    }
};
