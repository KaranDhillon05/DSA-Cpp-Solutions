/*
 * Day: 217 | Date: 2024-09-04
 * Q217: Number of Longest Increasing Subsequence (Segment Tree)
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
    int findNumberOfLIS(vector<int>& nums) {
        vector<int> vals = nums;
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());
        int n = vals.size();
        vector<int> len(n + 1), cnt(n + 1);
        int best = 0, ways = 0;
        for (int x : nums) {
            int id = lower_bound(vals.begin(), vals.end(), x) - vals.begin() + 1;
            int l = 1, c = 1;
            for (int i = id; i > 0; i -= i & -i) if (len[i]) {
                if (len[i] + 1 > l) { l = len[i] + 1; c = cnt[i]; }
                else if (len[i] + 1 == l) c += cnt[i];
            }
            for (int i = id; i <= n; i += i & -i) {
                if (l > len[i]) { len[i] = l; cnt[i] = c; }
                else if (l == len[i]) cnt[i] += c;
            }
            if (l > best) { best = l; ways = c; }
            else if (l == best) ways += c;
        }
        return ways;
    }
};
