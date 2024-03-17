/*
 * Day: 46 | Date: 2024-03-17
 * Q046: Kth Largest Element in an Array
 * Difficulty: Medium
 * Pattern: Sorting & Searching
 * Section: 1.5 Sorting & Searching
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (int x : nums) {
            minHeap.push(x);
            if ((int)minHeap.size() > k) minHeap.pop();
        }
        return minHeap.top();
    }
};
