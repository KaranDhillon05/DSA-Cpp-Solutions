/*
 * Day: 420 | Date: 2025-03-26
 * Q420: Construct the Lexicographically Largest Valid Sequence
 * Difficulty: Hard
 * Pattern: Backtracking
 * Section: 10 Backtracking
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool dfs(int pos, int m, vector<int>& nums, vector<bool>& used) {
        if (pos == (int)nums.size()) return true;
        if (nums[pos] != 0) return dfs(pos + 1, m, nums, used);
        for (int v = m; v >= 1; --v) {
            if (used[v]) continue;
            nums[pos] = v;
            used[v] = true;
            if (dfs(pos + 1, m, nums, used)) return true;
            nums[pos] = 0;
            used[v] = false;
        }
        return false;
    }
public:
    vector<int> constructDistancedSequence(int n) {
        int m = 2 * n - 1;
        vector<int> nums(m, 0);
        vector<bool> used(n + 1, false);
        dfs(0, n, nums, used);
        return nums;
    }
};
