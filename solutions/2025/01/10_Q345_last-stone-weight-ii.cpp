/*
 * Day: 345 | Date: 2025-01-10
 * Q345: Last Stone Weight II
 * Difficulty: Medium
 * Pattern: Knapsack
 * Section: Dynamic Programming
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum=accumulate(stones.begin(), stones.end(), 0);
        vector<bool> dp(sum/2+1); dp[0]=true;
        for (int s:stones) for (int i=sum/2;i>=s;--i) dp[i]=dp[i]||dp[i-s];
        for (int i=sum/2;i>=0;--i) if (dp[i]) return sum-2*i;
        return 0;
    }
};
