/*
 * Day: 334 | Date: 2024-12-30
 * Q334: Edit Distance
 * Difficulty: Hard
 * Pattern: 2-D DP
 * Section: Dynamic Programming
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m=word1.size(), n=word2.size();
        vector<int> dp(n+1);
        iota(dp.begin(), dp.end(), 0);
        for (int i=1;i<=m;++i){
            int prev=dp[0]; dp[0]=i;
            for (int j=1;j<=n;++j){
                int tmp=dp[j];
                if (word1[i-1]==word2[j-1]) dp[j]=prev;
                else dp[j]=1+min({prev,dp[j],dp[j-1]});
                prev=tmp;
            }
        }
        return dp[n];
    }
};
