/*
 * Day: 247 | Date: 2024-10-04
 * Q247: Ugly Number II
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
    int nthUglyNumber(int n) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        pq.push(1);
        long long ugly = 1;
        while (n--) {
            ugly = pq.top(); pq.pop();
            if (ugly % 2 == 0) pq.push(ugly * 2);
            else if (ugly % 3 == 0) pq.push(ugly * 2), pq.push(ugly * 3);
            else pq.push(ugly * 2), pq.push(ugly * 3), pq.push(ugly * 5);
        }
        return (int)ugly;
    }
};
