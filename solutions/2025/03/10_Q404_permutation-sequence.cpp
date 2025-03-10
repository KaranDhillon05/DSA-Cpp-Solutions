/*
 * Day: 404 | Date: 2025-03-10
 * Q404: Permutation Sequence
 * Difficulty: Hard
 * Pattern: Backtracking
 * Section: 10 Backtracking
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> nums(n);
        iota(nums.begin(), nums.end(), 1);
        vector<int> fact(n + 1, 1);
        for (int i = 1; i <= n; ++i) fact[i] = fact[i - 1] * i;
        --k;
        string res;
        vector<bool> used(n, false);
        for (int i = 0; i < n; ++i) {
            int cnt = k / fact[n - 1 - i];
            for (int j = 0; j < n; ++j) {
                if (used[j]) continue;
                if (cnt == 0) { res += char('0' + nums[j]); used[j] = true; break; }
                --cnt;
            }
            k %= fact[n - 1 - i];
        }
        return res;
    }
};
