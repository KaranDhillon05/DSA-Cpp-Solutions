/*
 * Day: 313 | Date: 2024-12-09
 * Q313: House Robber II
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
        if (nums.size()==1) return nums[0];
        auto robRange=[&](int l,int r){
            int prev=0, cur=0;
            for (int i=l;i<=r;++i){ int t=max(cur,prev+nums[i]); prev=cur; cur=t; }
            return cur;
        };
        return max(robRange(0,(int)nums.size()-2), robRange(1,(int)nums.size()-1));
    }
};
