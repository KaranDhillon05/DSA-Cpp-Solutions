/*
 * Day: 175 | Date: 2024-07-24
 * Q175: Number of Longest Increasing Subsequence
 * Difficulty: Medium
 * Pattern: Bisect
 * Section: Binary Search
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<pair<int,int>> dp;
        int best = 0, cnt = 0;
        for (int x : nums) {
            int len = 1, ways = 1;
            for (auto& [l, c] : dp) if (l < x) {
                if (l + 1 > len) { len = l + 1; ways = c; }
                else if (l + 1 == len) ways += c;
            }
            if (len > best) { best = len; cnt = ways; }
            else if (len == best) cnt += ways;
            dp.push_back({len, ways});
        }
        return cnt;
    }
};
