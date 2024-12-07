/*
 * Day: 311 | Date: 2024-12-07
 * Q311: Climbing Stairs
 * Difficulty: Easy
 * Pattern: 1-D DP
 * Section: Dynamic Programming
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n<=2) return n;
        int a=1,b=2;
        for (int i=3;i<=n;++i){ int c=a+b; a=b; b=c; }
        return b;
    }
};
