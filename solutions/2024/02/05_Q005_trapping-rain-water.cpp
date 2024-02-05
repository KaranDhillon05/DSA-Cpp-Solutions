/*
 * Day: 5 | Date: 2024-02-05
 * Q005: Trapping Rain Water
 * Difficulty: Hard
 * Pattern: Two Pointers
 * Section: 1.1 Two Pointers
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = (int)height.size() - 1;
        int leftMax = 0, rightMax = 0, water = 0;
        while (l < r) {
            if (height[l] <= height[r]) {
                leftMax = max(leftMax, height[l]);
                water += leftMax - height[l];
                ++l;
            } else {
                rightMax = max(rightMax, height[r]);
                water += rightMax - height[r];
                --r;
            }
        }
        return water;
    }
};
