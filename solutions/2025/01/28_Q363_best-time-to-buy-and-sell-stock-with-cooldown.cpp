/*
 * Day: 363 | Date: 2025-01-28
 * Q363: Best Time to Buy and Sell Stock with Cooldown
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
    int maxProfit(vector<int>& prices) {
        int sold=0, hold=INT_MIN, rest=0;
        for (int p:prices){
            int prevSold=sold;
            sold=hold+p;
            hold=max(hold, rest-p);
            rest=max(rest, prevSold);
        }
        return max(sold, rest);
    }
};
