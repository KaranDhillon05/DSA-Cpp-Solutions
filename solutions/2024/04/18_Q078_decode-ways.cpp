/*
 * Day: 78 | Date: 2024-04-18
 * Q078: Decode Ways
 * Difficulty: Medium
 * Pattern: DP
 * Section: 2.3
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<long long> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; ++i) {
            if (s[i - 1] != '0') dp[i] += dp[i - 1];
            if (i >= 2) {
                int val = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
                if (val >= 10 && val <= 26) dp[i] += dp[i - 2];
            }
        }
        return (int)dp[n];
    }
};
