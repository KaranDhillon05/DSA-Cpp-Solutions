/*
 * Day: 248 | Date: 2024-10-05
 * Q248: Super Ugly Number
 * Difficulty: Medium
 * Pattern: Two-Heap Pattern
 * Section: Heaps & Priority Queues
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<long long> ugly(n, 1);
        vector<int> idx(primes.size(), 0);
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;
        for (int i = 0; i < (int)primes.size(); ++i)
            pq.push({primes[i], i});
        for (int i = 1; i < n; ++i) {
            ugly[i] = pq.top().first;
            while (!pq.empty() && pq.top().first == ugly[i]) {
                int j = pq.top().second; pq.pop();
                pq.push({ugly[++idx[j]] * primes[j], j});
            }
        }
        return (int)ugly[n-1];
    }
};
