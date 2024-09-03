/*
 * Day: 216 | Date: 2024-09-03
 * Q216: Count of Range Sum
 * Difficulty: Hard
 * Pattern: Segment Tree / BIT
 * Section: Trees
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
    long long mergeSort(vector<long long>& pref, int lo, int hi, int lower, int upper) {
        if (lo >= hi) return 0;
        int mid = lo + (hi - lo) / 2;
        long long ans = mergeSort(pref, lo, mid, lower, upper) + mergeSort(pref, mid + 1, hi, lower, upper);
        int j = mid + 1, k = mid + 1;
        for (int i = lo; i <= mid; ++i) {
            while (j <= hi && pref[j] - pref[i] < lower) ++j;
            while (k <= hi && pref[k] - pref[i] <= upper) ++k;
            ans += k - j;
        }
        inplace_merge(pref.begin() + lo, pref.begin() + mid + 1, pref.begin() + hi + 1);
        return ans;
    }
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        vector<long long> pref(nums.size() + 1);
        for (int i = 0; i < (int)nums.size(); ++i) pref[i + 1] = pref[i] + nums[i];
        return (int)mergeSort(pref, 0, pref.size() - 1, lower, upper);
    }
};
