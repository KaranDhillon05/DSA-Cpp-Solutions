/*
 * Day: 324 | Date: 2024-12-20
 * Q324: Ugly Number III
 * Difficulty: Medium
 * Pattern: 1-D DP
 * Section: Dynamic Programming
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n, long long a, long long b, long long c) {
        long long lo=1, hi=2e9;
        while (lo<hi){
            long long mid=lo+(hi-lo)/2;
            long long cnt=mid/a+mid/b+mid/c-mid/lcm(a,b)-mid/lcm(a,c)-mid/lcm(b,c)+mid/lcm(lcm(a,b),c);
            if (cnt>=n) hi=mid; else lo=mid+1;
        }
        return (int)lo;
    }
private:
    long long gcd(long long x,long long y){ return y?gcd(y,x%y):x; }
    long long lcm(long long x,long long y){ return x/gcd(x,y)*y; }
};
