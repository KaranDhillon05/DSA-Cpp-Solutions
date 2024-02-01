/*
 * Day: 1 | Date: 2024-02-01
 * Q001: Two Sum (sorted array)
 * Difficulty: Easy
 * Pattern: Two Pointers
 * Section: 1.1 Two Pointers
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = (int)numbers.size() - 1;
        while (l < r) {
            long long sum = (long long)numbers[l] + numbers[r];
            if (sum == target) return {l + 1, r + 1};
            if (sum < target) ++l;
            else --r;
        }
        return {};
    }
};
