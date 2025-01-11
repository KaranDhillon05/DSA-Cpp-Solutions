/*
 * Day: 346 | Date: 2025-01-11
 * Q346: Ones and Zeroes
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
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1));
        for (auto& s:strs){
            int z=count(s.begin(), s.end(), '0'), o=s.size()-z;
            for (int i=m;i>=z;--i) for (int j=n;j>=o;--j)
                dp[i][j]=max(dp[i][j], dp[i-z][j-o]+1);
        }
        return dp[m][n];
    }
};
