/*
 * Day: 479 | Date: 2025-05-24
 * Q479: Shuffle an Array
 * Difficulty: Medium
 * Pattern: Design
 * Section: 13 Design
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> orig;
    mt19937 rng{random_device{}()};
public:
    Solution(vector<int>& nums) : orig(nums) {}
    vector<int> reset() { return orig; }
    vector<int> shuffle() {
        vector<int> arr = orig;
        for (int i = arr.size() - 1; i > 0; --i)
            swap(arr[i], arr[rng() % (i + 1)]);
        return arr;
    }
};
