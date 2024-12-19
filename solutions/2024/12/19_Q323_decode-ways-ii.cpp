/*
 * Day: 323 | Date: 2024-12-19
 * Q323: Decode Ways II
 * Difficulty: Hard
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
        const int MOD=1e9+7;
        int n=s.size(); vector<long long> dp(n+1); dp[0]=1;
        for (int i=1;i<=n;++i){
            if (s[i-1]=='*') dp[i]=dp[i]*4+dp[i-1]*9;
            else if (s[i-1]!='0') dp[i]=dp[i-1];
            if (i>=2){
                if (s[i-2]=='*'&&s[i-1]=='*') dp[i]+=dp[i-2]*15;
                else if (s[i-2]=='*') dp[i]+=dp[i-2]*(s[i-1]<='6'?2:1);
                else if (s[i-1]=='*') dp[i]+=dp[i-2]*(s[i-2]=='1'?9:s[i-2]=='2'?6:0);
                else { int two=(s[i-2]-'0')*10+(s[i-1]-'0'); if(two>=10&&two<=26) dp[i]+=dp[i-2]; }
            }
            dp[i]%=MOD;
        }
        return (int)dp[n];
    }
};
