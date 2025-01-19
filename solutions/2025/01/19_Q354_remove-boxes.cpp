/*
 * Day: 354 | Date: 2025-01-19
 * Q354: Remove Boxes
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
    int removeBoxes(vector<int>& boxes) {
        int n=boxes.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n)));
        function<int(int,int,int)> f=[&](int l,int r,int k){
            if (l>r) return 0;
            if (dp[l][r][k]) return dp[l][r][k];
            while (r>l&&boxes[r]==boxes[l]){ ++k; --r; }
            dp[l][r][k]=f(l,r-1,0)+(k+1)*(k+1);
            for (int i=l;i<r;++i)
                if (boxes[i]==boxes[r])
                    dp[l][r][k]=max(dp[l][r][k], f(l,i,k+1)+f(i+1,r-1,0));
            return dp[l][r][k];
        };
        return f(0,n-1,0);
    }
};
