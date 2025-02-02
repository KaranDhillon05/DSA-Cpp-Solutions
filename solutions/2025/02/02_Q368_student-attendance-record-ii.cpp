/*
 * Day: 368 | Date: 2025-02-02
 * Q368: Student Attendance Record II
 * Difficulty: Hard
 * Pattern: State-Machine DP
 * Section: Dynamic Programming
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int checkRecord(int n) {
        const int MOD=1e9+7;
        vector<vector<long long>> dp(n+1, vector<long long>(6));
        dp[0][0]=1;
        for (int i=1;i<=n;++i){
            dp[i][0]=(dp[i-1][0]+dp[i-1][1]+dp[i-1][2])%MOD;
            dp[i][1]=(dp[i-1][3]+dp[i-1][4]+dp[i-1][5])%MOD;
            dp[i][2]=dp[i-1][0];
            dp[i][3]=(dp[i-1][0]+dp[i-1][1]+dp[i-1][2])%MOD;
            dp[i][4]=dp[i-1][3];
            dp[i][5]=dp[i-1][4];
        }
        long long ans=0;
        for (int s=0;s<6;++s) ans=(ans+dp[n][s])%MOD;
        return (int)ans;
    }
};
