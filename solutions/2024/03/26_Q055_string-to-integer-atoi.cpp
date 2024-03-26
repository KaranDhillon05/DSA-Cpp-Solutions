/*
 * Day: 55 | Date: 2024-03-26
 * Q055: String to Integer (atoi)
 * Difficulty: Medium
 * Pattern: String Basics
 * Section: 2.1
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.size();
        while (i < n && s[i] == ' ') ++i;
        if (i == n) return 0;
        int sign = 1;
        if (s[i] == '+' || s[i] == '-') sign = s[i++] == '-' ? -1 : 1;
        long val = 0;
        while (i < n && isdigit(s[i])) {
            val = val * 10 + (s[i++] - '0');
            if (sign == 1 && val > INT_MAX) return INT_MAX;
            if (sign == -1 && -val < INT_MIN) return INT_MIN;
        }
        return (int)(sign * val);
    }
};
