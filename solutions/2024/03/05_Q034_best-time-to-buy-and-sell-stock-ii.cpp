/*
 * Day: 34 | Date: 2024-03-05
 * Q034: Best Time to Buy and Sell Stock II
 * Difficulty: Medium
 * Pattern: Kadane's / Greedy
 * Section: 1.4 Kadane's / Greedy
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for (int i = 1; i < (int)prices.size(); ++i) {
            if (prices[i] > prices[i - 1]) {
                profit += prices[i] - prices[i - 1];
            }
        }
        return profit;
    }
};
