/*
 * Day: 315 | Date: 2024-12-11
 * Q315: Min Cost Climbing Stairs
 * Difficulty: Easy
 * Pattern: 1-D DP
 * Section: Dynamic Programming
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int a=0,b=0;
        for (int i=2;i<=(int)cost.size();++i){
            int c=min(b+cost[i-1], a+cost[i-2]);
            a=b; b=c;
        }
        return b;
    }
};
