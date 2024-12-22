/*
 * Day: 326 | Date: 2024-12-22
 * Q326: Unique Paths
 * Difficulty: Medium
 * Pattern: 2-D DP
 * Section: Dynamic Programming
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n,1);
        for (int i=1;i<m;++i)
            for (int j=1;j<n;++j) dp[j]+=dp[j-1];
        return dp[n-1];
    }
};
