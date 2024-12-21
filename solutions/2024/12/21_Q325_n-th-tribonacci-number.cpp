/*
 * Day: 325 | Date: 2024-12-21
 * Q325: N-th Tribonacci Number
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
    int tribonacci(int n) {
        if (n==0) return 0; if (n<=2) return 1;
        int a=0,b=1,c=1;
        for (int i=3;i<=n;++i){ int d=a+b+c; a=b; b=c; c=d; }
        return c;
    }
};
