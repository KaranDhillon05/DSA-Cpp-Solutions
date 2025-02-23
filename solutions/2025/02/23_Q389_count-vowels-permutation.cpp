/*
 * Day: 389 | Date: 2025-02-23
 * Q389: Count Vowels Permutation
 * Difficulty: Hard
 * Pattern: Tree/Graph DP
 * Section: Dynamic Programming
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countVowelPermutation(int n) {
        const int MOD=1e9+7;
        long long a=1,e=1,i=1,o=1,u=1;
        for (int t=2;t<=n;++t){
            long long na=(e+i+u)%MOD;
            long long ne=(a+i)%MOD;
            long long ni=(e+i)%MOD;
            long long no=a;
            long long nu=(i+o)%MOD;
            a=na;e=ne;i=ni;o=no;u=nu;
        }
        return (int)((a+e+i+o+u)%MOD);
    }
};
