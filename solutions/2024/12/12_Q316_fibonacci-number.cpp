/*
 * Day: 316 | Date: 2024-12-12
 * Q316: Fibonacci Number
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
    int fib(int n) {
        if (n<=1) return n;
        int a=0,b=1;
        for (int i=2;i<=n;++i){ int c=a+b; a=b; b=c; }
        return b;
    }
};
