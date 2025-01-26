/*
 * Day: 361 | Date: 2025-01-26
 * Q361: Best Time to Buy and Sell Stock III
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
    int maxProfit(vector<int>& prices) {
        int buy1=INT_MAX, buy2=INT_MAX, sell1=0, sell2=0;
        for (int p:prices){
            buy1=min(buy1,p);
            sell1=max(sell1,p-buy1);
            buy2=min(buy2,p-sell1);
            sell2=max(sell2,p-buy2);
        }
        return sell2;
    }
};
