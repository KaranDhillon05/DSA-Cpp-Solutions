/*
 * Day: 293 | Date: 2024-11-19
 * Q293: Satisfiability of Equality Equations
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
    bool equationsPossible(vector<string>& equations) {
        vector<int> p(26); iota(p.begin(), p.end(), 0);
        function<int(int)> f = [&](int x){ return p[x]==x?x:p[x]=f(p[x]); };
        for (auto& e:equations) if(e[1]=='=') p[f(e[0]-'a')]=f(e[3]-'a');
        for (auto& e:equations) if(e[1]=='!'&&f(e[0]-'a')==f(e[3]-'a')) return false;
        return true;
    }
};
