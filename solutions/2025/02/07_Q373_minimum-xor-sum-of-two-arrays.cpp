/*
 * Day: 373 | Date: 2025-02-07
 * Q373: Minimum XOR Sum of Two Arrays
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
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        vector<int> dp(1<<n, INT_MAX); dp[0]=0;
        for (int mask=0; mask<(1<<n); ++mask)
            for (int j=0;j<n;++j)
                if (!(mask&(1<<j)))
                    dp[mask|(1<<j)]=min(dp[mask|(1<<j)], dp[mask]+(nums1[j]^nums2[__builtin_popcount(mask)]));
        return dp[(1<<n)-1];
    }
};
