/*
 * Day: 377 | Date: 2025-02-11
 * Q377: Number of Ways to Wear Different Hats to Each Other
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
    int numberWays(vector<vector<int>>& hats) {
        const int MOD=1e9+7;
        int n=hats.size(), m=0;
        for (auto& h:hats) m=max(m, (int)h.size());
        vector<vector<int>> hatToPeople(41);
        for (int i=0;i<n;++i) for (int h:hats[i]) hatToPeople[h].push_back(i);
        vector<long long> dp(1<<n); dp[0]=1;
        for (int hat=1; hat<=40; ++hat){
            vector<long long> nd=dp;
            for (int p:hatToPeople[hat])
                for (int mask=0; mask<(1<<n); ++mask)
                    if (!(mask&(1<<p))) nd[mask|(1<<p)]=(nd[mask|(1<<p)]+dp[mask])%MOD;
            dp.swap(nd);
        }
        return (int)dp[(1<<n)-1];
    }
};
