/*
 * Day: 312 | Date: 2024-12-08
 * Q312: House Robber
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
    int rob(vector<int>& nums) {
        int prev=0, cur=0;
        for (int x:nums){ int t=max(cur,prev+x); prev=cur; cur=t; }
        return cur;
    }
};
