/*
 * Day: 380 | Date: 2025-02-14
 * Q380: Find the Shortest Superstring
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
    string shortestSuperstring(vector<string>& words) {
        int n=words.size();
        vector<vector<int>> overlap(n, vector<int>(n));
        for (int i=0;i<n;++i) for (int j=0;j<n;++j) if (i!=j)
            for (int k=min((int)words[i].size(),(int)words[j].size()); k>0; --k)
                if (words[i].substr(words[i].size()-k)==words[j].substr(0,k)){ overlap[i][j]=k; break; }
        vector<vector<int>> dp(1<<n, vector<int>(n));
        vector<vector<int>> parent(1<<n, vector<int>(n, -1));
        for (int mask=1; mask<(1<<n); ++mask)
            for (int last=0; last<n; ++last) if (mask&(1<<last)){
                int pmask=mask^(1<<last);
                if (!pmask){ dp[mask][last]=0; continue; }
                for (int prev=0; prev<n; ++prev) if (pmask&(1<<prev)){
                    int val=dp[pmask][prev]+overlap[prev][last];
                    if (val>dp[mask][last]){ dp[mask][last]=val; parent[mask][last]=prev; }
                }
            }
        int mask=(1<<n)-1, last=0, best=-1;
        for (int i=0;i<n;++i) if (dp[mask][i]>best){ best=dp[mask][i]; last=i; }
        string res=words[last]; mask^=(1<<last);
        while (mask){
            int prev=parent[mask|(1<<last)][last];
            res=words[prev]+res.substr(overlap[prev][last]);
            mask^=(1<<prev); last=prev;
        }
        return res;
    }
};
