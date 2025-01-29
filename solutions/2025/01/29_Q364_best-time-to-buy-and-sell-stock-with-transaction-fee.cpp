/*
 * Day: 364 | Date: 2025-01-29
 * Q364: Best Time to Buy and Sell Stock with Transaction Fee
 * Difficulty: Medium
 * Pattern: State-Machine DP
 * Section: Dynamic Programming
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int cash=0, hold=-prices[0];
        for (int i=1;i<(int)prices.size();++i){
            cash=max(cash, hold+prices[i]-fee);
            hold=max(hold, cash-prices[i]);
        }
        return cash;
    }
};
