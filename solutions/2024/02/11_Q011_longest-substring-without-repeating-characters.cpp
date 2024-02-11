/*
 * Day: 11 | Date: 2024-02-11
 * Q011: Longest Substring Without Repeating Characters
 * Difficulty: Medium
 * Pattern: Sliding Window
 * Section: 1.2 Sliding Window
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> last(256, -1);
        int l = 0, best = 0;
        for (int r = 0; r < (int)s.size(); ++r) {
            if (last[(unsigned char)s[r]] >= l) {
                l = last[(unsigned char)s[r]] + 1;
            }
            last[(unsigned char)s[r]] = r;
            best = max(best, r - l + 1);
        }
        return best;
    }
};
