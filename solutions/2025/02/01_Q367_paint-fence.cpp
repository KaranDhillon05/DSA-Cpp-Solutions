/*
 * Day: 367 | Date: 2025-02-01
 * Q367: Paint Fence
 * Difficulty: Medium
 * Pattern: State-Machine DP
 * Section: Dynamic Programming
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numWays(int n, int k) {
        if (n==1) return k;
        long long same=k, diff=(long long)k*(k-1);
        for (int i=2;i<=n;++i){
            long long nsame=diff;
            long long ndiff=(same+diff)*(k-1);
            same=nsame; diff=ndiff;
        }
        return (int)(same+diff);
    }
};
