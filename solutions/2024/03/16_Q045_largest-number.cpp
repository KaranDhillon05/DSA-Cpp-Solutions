/*
 * Day: 45 | Date: 2024-03-16
 * Q045: Largest Number
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
    string largestNumber(vector<int>& nums) {
        vector<string> strs;
        for (int x : nums) strs.push_back(to_string(x));
        sort(strs.begin(), strs.end(), [](const string& a, const string& b) {
            return a + b > b + a;
        });
        if (strs[0] == "0") return "0";
        string res;
        for (const string& s : strs) res += s;
        return res;
    }
};
