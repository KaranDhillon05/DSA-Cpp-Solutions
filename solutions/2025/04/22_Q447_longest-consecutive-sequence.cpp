/*
 * Day: 447 | Date: 2025-04-22
 * Q447: Longest Consecutive Sequence
 * Difficulty: Medium
 * Pattern: Hashing
 * Section: 12 Hashing & Math
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int best = 0;
        for (int x : s) {
            if (s.count(x - 1)) continue;
            int len = 1;
            while (s.count(x + len)) ++len;
            best = max(best, len);
        }
        return best;
    }
};
