/*
 * Day: 360 | Date: 2025-01-25
 * Q360: Maximum Coins You Can Get
 * Difficulty: Medium
 * Pattern: Interval DP
 * Section: Dynamic Programming
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        int ans=0, n=piles.size();
        for (int i=n/3;i<n;i+=2) ans+=piles[i];
        return ans;
    }
};
