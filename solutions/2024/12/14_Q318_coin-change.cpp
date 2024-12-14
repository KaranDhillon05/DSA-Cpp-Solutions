/*
 * Day: 318 | Date: 2024-12-14
 * Q318: Coin Change
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
    int coinChange(vector<int>& coins, int amount) {
        const int INF=amount+1;
        vector<int> dp(amount+1,INF); dp[0]=0;
        for (int a=1;a<=amount;++a)
            for (int c:coins) if(c<=a) dp[a]=min(dp[a],dp[a-c]+1);
        return dp[amount]==INF?-1:dp[amount];
    }
};
