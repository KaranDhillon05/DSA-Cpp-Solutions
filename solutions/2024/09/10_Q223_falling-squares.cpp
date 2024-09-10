/*
 * Day: 223 | Date: 2024-09-10
 * Q223: Falling Squares
 * Difficulty: Hard
 * Pattern: Segment Tree / BIT
 * Section: Trees
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        vector<int> ans;
        map<int,int> height;
        int best = 0;
        for (auto& p : positions) {
            int left = p[0], side = p[1], right = left + side;
            int base = 0;
            auto it = height.lower_bound(left);
            if (it != height.begin()) {
                auto prev = std::prev(it);
                if (prev->first + prev->second > left) base = max(base, prev->second);
            }
            while (it != height.end() && it->first < right) {
                base = max(base, it->second);
                it = height.erase(it);
            }
            int top = base + side;
            height[left] = top;
            best = max(best, top);
            ans.push_back(best);
        }
        return ans;
    }
};
