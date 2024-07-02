/*
 * Day: 153 | Date: 2024-07-02
 * Q153: Kth Smallest Element in a Sorted Matrix
 * Difficulty: Medium
 * Pattern: Classic
 * Section: Binary Search
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int lo = matrix[0][0], hi = matrix[n-1][n-1];
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2, cnt = 0;
            for (int i = 0, j = n - 1; i < n; ++i) {
                while (j >= 0 && matrix[i][j] > mid) --j;
                cnt += j + 1;
            }
            if (cnt < k) lo = mid + 1; else hi = mid;
        }
        return lo;
    }
};
