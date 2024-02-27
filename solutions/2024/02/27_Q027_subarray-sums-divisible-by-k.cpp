/*
 * Day: 27 | Date: 2024-02-27
 * Q027: Subarray Sums Divisible by K
 * Difficulty: Medium
 * Pattern: Prefix Sum
 * Section: 1.3 Prefix Sum
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> remCount(k, 0);
        remCount[0] = 1;
        int sum = 0, count = 0;
        for (int x : nums) {
            sum += x;
            int rem = ((sum % k) + k) % k;
            count += remCount[rem];
            ++remCount[rem];
        }
        return count;
    }
};
