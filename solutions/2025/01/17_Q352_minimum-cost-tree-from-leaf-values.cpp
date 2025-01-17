/*
 * Day: 352 | Date: 2025-01-17
 * Q352: Minimum Cost Tree From Leaf Values
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
    int mctFromLeafValues(vector<int>& arr) {
        int n=arr.size(); vector<vector<int>> dp(n, vector<int>(n,INT_MAX)), mx(n, vector<int>(n));
        for (int i=0;i<n;++i){ mx[i][i]=arr[i]; dp[i][i]=0; }
        for (int len=2; len<=n; ++len)
            for (int i=0;i+len-1<n;++i){
                int j=i+len-1;
                for (int k=i;k<j;++k){
                    mx[i][j]=max(mx[i][j], max(mx[i][k], mx[k+1][j]));
                    dp[i][j]=min(dp[i][j], dp[i][k]+dp[k+1][j]+mx[i][k]*mx[k+1][j]);
                }
            }
        return dp[0][n-1];
    }
};
