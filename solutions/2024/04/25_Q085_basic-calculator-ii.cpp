/*
 * Day: 85 | Date: 2024-04-25
 * Q085: Basic Calculator II
 * Difficulty: Medium
 * Pattern: Stack
 * Section: 2.4
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        long long num = 0, res = 0, last = 0;
        char op = '+';
        for (int i = 0; i <= (int)s.size(); ++i) {
            if (i < (int)s.size() && isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
            } else if (i == (int)s.size() || s[i] != ' ') {
                if (op == '+') { res += last; last = num; }
                else if (op == '-') { res += last; last = -num; }
                else if (op == '*') last *= num;
                else if (op == '/') last /= num;
                op = i < (int)s.size() ? s[i] : '+';
                num = 0;
            }
        }
        return (int)(res + last);
    }
};
