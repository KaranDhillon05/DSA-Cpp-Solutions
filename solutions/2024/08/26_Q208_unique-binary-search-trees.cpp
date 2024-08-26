/*
 * Day: 208 | Date: 2024-08-26
 * Q208: Unique Binary Search Trees
 * Difficulty: Medium
 * Pattern: BST
 * Section: Trees
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
        vector<long long> dp(n + 1);
        dp[0] = dp[1] = 1;
        for (int nodes = 2; nodes <= n; ++nodes)
            for (int root = 1; root <= nodes; ++root)
                dp[nodes] += dp[root - 1] * dp[nodes - root];
        return (int)dp[n];
    }
};
