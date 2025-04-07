/*
 * Day: 432 | Date: 2025-04-07
 * Q432: Largest Number
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
    string largestNumber(vector<int>& nums) {
        vector<string> s;
        for (int x : nums) s.push_back(to_string(x));
        sort(s.begin(), s.end(), [](const string& a, const string& b) {
            return a + b > b + a;
        });
        if (s[0] == "0") return "0";
        string res;
        for (auto& x : s) res += x;
        return res;
    }
};
