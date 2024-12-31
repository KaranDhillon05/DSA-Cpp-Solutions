/*
 * Day: 335 | Date: 2024-12-31
 * Q335: Distinct Subsequences
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
    int numDistinct(string s, string t) {
        int m=s.size(), n=t.size();
        vector<unsigned long long> dp(n+1); dp[0]=1;
        for (int i=1;i<=m;++i)
            for (int j=n;j>=1;--j)
                if (s[i-1]==t[j-1]) dp[j]+=dp[j-1];
        return (int)dp[n];
    }
};
