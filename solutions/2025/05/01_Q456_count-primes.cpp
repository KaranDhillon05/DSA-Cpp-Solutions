/*
 * Day: 456 | Date: 2025-05-01
 * Q456: Count Primes
 * Difficulty: Medium
 * Pattern: Math
 * Section: 12 Hashing & Math
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;
        vector<bool> prime(n, true);
        prime[0] = prime[1] = false;
        for (int i = 2; i * i < n; ++i)
            if (prime[i])
                for (int j = i * i; j < n; j += i) prime[j] = false;
        return count(prime.begin(), prime.end(), true);
    }
};
