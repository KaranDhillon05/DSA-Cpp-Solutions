/*
 * Day: 374 | Date: 2025-02-08
 * Q374: Maximum Students Taking Exam
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
    int maxStudents(vector<vector<char>>& seats) {
        int m=seats.size(), n=seats[0].size();
        vector<int> row(m);
        for (int i=0;i<m;++i)
            for (int j=0;j<n;++j) if (seats[i][j]=='.') row[i]|=(1<<j);
        vector<vector<int>> dp(m, vector<int>(1<<n, -1));
        function<int(int,int)> f=[&](int r,int mask){
            if (r==m) return 0;
            if (dp[r][mask]!=-1) return dp[r][mask];
            int best=0;
            for (int cand=0;cand<(1<<n);++cand){
                if (cand&~row[r]) continue;
                if (cand&(cand<<1)) continue;
                if (mask&(cand<<1)||mask&(cand>>1)) continue;
                best=max(best, __builtin_popcount(cand)+f(r+1,cand));
            }
            return dp[r][mask]=best;
        };
        return f(0,0);
    }
};
