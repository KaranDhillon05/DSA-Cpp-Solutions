/*
 * Day: 320 | Date: 2024-12-16
 * Q320: Perfect Squares
 * Difficulty: Medium
 * Pattern: 1-D DP
 * Section: Dynamic Programming
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1,INT_MAX); dp[0]=0;
        for (int i=1;i<=n;++i)
            for (int j=1;j*j<=i;++j) dp[i]=min(dp[i],dp[i-j*j]+1);
        return dp[n];
    }
};
