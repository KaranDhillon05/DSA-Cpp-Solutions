/*
 * Day: 319 | Date: 2024-12-15
 * Q319: Coin Change II
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
    int change(int amount, vector<int>& coins) {
        vector<long long> dp(amount+1); dp[0]=1;
        for (int c:coins) for (int a=c;a<=amount;++a) dp[a]+=dp[a-c];
        return (int)dp[amount];
    }
};
