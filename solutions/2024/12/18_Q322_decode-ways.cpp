/*
 * Day: 322 | Date: 2024-12-18
 * Q322: Decode Ways
 * Difficulty: Medium
 * Pattern: 1-D DP
 * Section: Dynamic Programming
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        if (!s.size()||s[0]=='0') return 0;
        int n=s.size(); vector<int> dp(n+1); dp[0]=1; dp[1]=1;
        for (int i=2;i<=n;++i){
            if (s[i-1]!='0') dp[i]+=dp[i-1];
            int two=(s[i-2]-'0')*10+(s[i-1]-'0');
            if (two>=10&&two<=26) dp[i]+=dp[i-2];
        }
        return dp[n];
    }
};
