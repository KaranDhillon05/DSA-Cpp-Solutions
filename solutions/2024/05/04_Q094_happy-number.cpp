/*
 * Day: 94 | Date: 2024-05-04
 * Q094: Happy Number
 * Difficulty: Easy
 * Pattern: Fast & Slow Pointers
 * Section: 3.1
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
    int nextNum(int n) {
        int sum = 0;
        while (n) { int d = n % 10; sum += d * d; n /= 10; }
        return sum;
    }
public:
    bool isHappy(int n) {
        int slow = n, fast = nextNum(n);
        while (fast != 1 && slow != fast) {
            slow = nextNum(slow);
            fast = nextNum(nextNum(fast));
        }
        return fast == 1;
    }
};
