/*
 * Day: 6 | Date: 2024-02-06
 * Q006: Remove Duplicates from Sorted Array
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
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int write = 1;
        for (int read = 1; read < (int)nums.size(); ++read) {
            if (nums[read] != nums[write - 1]) {
                nums[write++] = nums[read];
            }
        }
        return write;
    }
};
