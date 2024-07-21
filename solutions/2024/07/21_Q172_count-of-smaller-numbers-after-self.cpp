/*
 * Day: 172 | Date: 2024-07-21
 * Q172: Count of Smaller Numbers After Self
 * Difficulty: Hard
 * Pattern: Bisect
 * Section: Binary Search
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> bit;
    void add(int i, int v) { for (; i < (int)bit.size(); i += i & -i) bit[i] += v; }
    int sum(int i) { int s = 0; for (; i > 0; i -= i & -i) s += bit[i]; return s; }
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> vals = nums;
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());
        bit.assign(vals.size() + 1, 0);
        vector<int> ans(nums.size());
        for (int i = (int)nums.size() - 1; i >= 0; --i) {
            int id = lower_bound(vals.begin(), vals.end(), nums[i]) - vals.begin() + 1;
            ans[i] = sum(id - 1);
            add(id, 1);
        }
        return ans;
    }
};
