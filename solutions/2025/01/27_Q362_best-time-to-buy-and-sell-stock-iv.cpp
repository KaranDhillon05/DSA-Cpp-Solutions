/*
 * Day: 362 | Date: 2025-01-27
 * Q362: Best Time to Buy and Sell Stock IV
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
    int maxProfit(int k, vector<int>& prices) {
        if (k>=prices.size()/2){
            int p=0; for (int i=1;i<(int)prices.size();++i) if(prices[i]>prices[i-1]) p+=prices[i]-prices[i-1];
            return p;
        }
        vector<vector<int>> dp(k+1, vector<int>(prices.size()));
        for (int t=1;t<=k;++t){
            int best=-prices[0];
            for (int i=1;i<(int)prices.size();++i){
                dp[t][i]=max(dp[t][i-1], prices[i]+best);
                best=max(best, dp[t-1][i]-prices[i]);
            }
        }
        return dp[k][prices.size()-1];
    }
};
