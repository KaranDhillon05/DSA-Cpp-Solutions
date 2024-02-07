/*
 * Day: 7 | Date: 2024-02-07
 * Q007: Move Zeroes to End
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
    void moveZeroes(vector<int>& nums) {
        int write = 0;
        for (int read = 0; read < (int)nums.size(); ++read) {
            if (nums[read] != 0) {
                nums[write++] = nums[read];
            }
        }
        while (write < (int)nums.size()) nums[write++] = 0;
    }
};
