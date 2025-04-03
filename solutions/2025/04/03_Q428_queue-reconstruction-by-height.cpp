/*
 * Day: 428 | Date: 2025-04-03
 * Q428: Queue Reconstruction by Height
 * Difficulty: Medium
 * Pattern: Greedy
 * Section: 11 Greedy
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](auto& a, auto& b) {
            return a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]);
        });
        vector<vector<int>> res;
        for (auto& p : people) res.insert(res.begin() + p[1], p);
        return res;
    }
};
