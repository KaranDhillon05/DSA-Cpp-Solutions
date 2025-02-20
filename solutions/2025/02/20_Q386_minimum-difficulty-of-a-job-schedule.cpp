/*
 * Day: 386 | Date: 2025-02-20
 * Q386: Minimum Difficulty of a Job Schedule
 * Difficulty: Hard
 * Pattern: Tree/Graph DP
 * Section: Dynamic Programming
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n=jobDifficulty.size();
        if (n<d) return -1;
        vector<vector<int>> dp(d, vector<int>(n, INT_MAX));
        dp[0][0]=jobDifficulty[0];
        for (int i=1;i<n;++i) dp[0][i]=max(dp[0][i-1], jobDifficulty[i]);
        for (int day=1; day<d; ++day)
            for (int i=day;i<n;++i){
                int cur=jobDifficulty[i];
                for (int j=i;j>=day;--j){
                    cur=max(cur, jobDifficulty[j]);
                    dp[day][i]=min(dp[day][i], dp[day-1][j-1]+cur);
                }
            }
        return dp[d-1][n-1];
    }
};
