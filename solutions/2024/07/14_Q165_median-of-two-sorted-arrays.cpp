/*
 * Day: 165 | Date: 2024-07-14
 * Q165: Median of Two Sorted Arrays
 * Difficulty: Hard
 * Pattern: Parametric
 * Section: Binary Search
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);
        int m = nums1.size(), n = nums2.size(), lo = 0, hi = m;
        while (lo <= hi) {
            int i = lo + (hi - lo) / 2, j = (m + n + 1) / 2 - i;
            int maxL1 = i ? nums1[i-1] : INT_MIN, minR1 = i < m ? nums1[i] : INT_MAX;
            int maxL2 = j ? nums2[j-1] : INT_MIN, minR2 = j < n ? nums2[j] : INT_MAX;
            if (maxL1 <= minR2 && maxL2 <= minR1)
                return (m + n) % 2 ? max(maxL1, maxL2) : (max(maxL1, maxL2) + min(minR1, minR2)) / 2.0;
            if (maxL1 > minR2) hi = i - 1; else lo = i + 1;
        }
        return 0.0;
    }
};
