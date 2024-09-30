/*
 * Day: 243 | Date: 2024-09-30
 * Q243: Sliding Window Median
 * Difficulty: Hard
 * Pattern: Two-Heap Pattern
 * Section: Heaps & Priority Queues
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int> left, right;
        auto rebalance = [&]() {
            while ((int)left.size() > (int)right.size() + 1) {
                right.insert(*left.rbegin()); left.erase(prev(left.end()));
            }
            while ((int)right.size() > (int)left.size()) {
                left.insert(*right.begin()); right.erase(right.begin());
            }
        };
        vector<double> res;
        for (int i = 0; i < (int)nums.size(); ++i) {
            if (left.empty() || nums[i] <= *left.rbegin()) left.insert(nums[i]);
            else right.insert(nums[i]);
            rebalance();
            if (i >= k) {
                int out = nums[i - k];
                auto it = left.find(out);
                if (it != left.end()) left.erase(it);
                else right.erase(right.find(out));
                rebalance();
            }
            if (i >= k - 1) {
                if (k % 2) res.push_back(*left.rbegin());
                else res.push_back(((double)*left.rbegin() + *right.begin()) / 2.0);
            }
        }
        return res;
    }
};
