/*
 * Day: 336 | Date: 2025-01-01
 * Q336: Interleaving String
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
    bool isInterleave(string s1, string s2, string s3) {
        int m=s1.size(), n=s2.size();
        if ((int)s3.size()!=m+n) return false;
        vector<bool> dp(n+1);
        for (int i=0;i<=m;++i){
            for (int j=0;j<=n;++j){
                if (!i&&!j) dp[j]=true;
                else if (!i) dp[j]=dp[j]&&s2[j-1]==s3[j-1];
                else if (!j) dp[j]=dp[j]&&s1[i-1]==s3[i-1];
                else dp[j]=(s1[i-1]==s3[i+j-1]&&dp[j])||(s2[j-1]==s3[i+j-1]&&dp[j-1]);
            }
        }
        return dp[n];
    }
};
