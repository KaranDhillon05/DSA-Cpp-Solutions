/*
 * Day: 359 | Date: 2025-01-24
 * Q359: Palindrome Partitioning IV
 * Difficulty: Hard
 * Pattern: Interval DP
 * Section: Dynamic Programming
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkPartitioning(string s) {
        int n=s.size();
        vector<vector<bool>> pal(n, vector<bool>(n));
        for (int i=n-1;i>=0;--i)
            for (int j=i;j<n;++j)
                pal[i][j]=(s[i]==s[j])&&(j-i<2||pal[i+1][j-1]);
        for (int i=1;i<n-1;++i)
            for (int j=i+1;j<n;++j)
                if (pal[0][i-1]&&pal[i][j-1]&&pal[j][n-1]) return true;
        return false;
    }
};
