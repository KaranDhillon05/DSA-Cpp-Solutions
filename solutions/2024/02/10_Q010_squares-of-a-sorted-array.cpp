/*
 * Day: 10 | Date: 2024-02-10
 * Q010: Squares of a Sorted Array
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
    vector<int> sortedSquares(vector<int>& nums) {
        int n = (int)nums.size();
        vector<int> res(n);
        int l = 0, r = n - 1, pos = n - 1;
        while (l <= r) {
            int ll = nums[l] * nums[l];
            int rr = nums[r] * nums[r];
            if (ll > rr) {
                res[pos--] = ll;
                ++l;
            } else {
                res[pos--] = rr;
                --r;
            }
        }
        return res;
    }
};
