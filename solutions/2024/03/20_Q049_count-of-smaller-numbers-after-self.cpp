/*
 * Day: 49 | Date: 2024-03-20
 * Q049: Count of Smaller Numbers After Self
 * Difficulty: Hard
 * Pattern: Sorting & Searching
 * Section: 1.5 Sorting & Searching
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
    struct BIT {
        vector<int> tree;
        BIT(int n) : tree(n + 1, 0) {}
        void add(int i) {
            for (++i; i < (int)tree.size(); i += i & -i) ++tree[i];
        }
        int sum(int i) const {
            int res = 0;
            for (++i; i > 0; i -= i & -i) res += tree[i];
            return res;
        }
    };

public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
        BIT bit((int)sorted.size());
        vector<int> res(nums.size(), 0);
        for (int i = (int)nums.size() - 1; i >= 0; --i) {
            int rank = (int)(lower_bound(sorted.begin(), sorted.end(), nums[i]) - sorted.begin());
            res[i] = bit.sum(rank - 1);
            bit.add(rank);
        }
        return res;
    }
};
