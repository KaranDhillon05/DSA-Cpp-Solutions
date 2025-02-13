/*
 * Day: 379 | Date: 2025-02-13
 * Q379: Maximize Score After N Operations
 * Difficulty: Hard
 * Pattern: Bitmask DP
 * Section: Dynamic Programming
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(1<<n, vector<int>(n+1, -1));
        function<int(int,int)> f=[&](int mask,int step){
            if (!mask) return 0;
            if (dp[mask][step]!=-1) return dp[mask][step];
            int best=0;
            for (int i=0;i<n;++i) if (mask&(1<<i)){
                int score=step*__builtin_gcd(step, nums[i]);
                best=max(best, score+f(mask^(1<<i), step+1));
            }
            return dp[mask][step]=best;
        };
        return f((1<<n)-1,1);
    }
};
