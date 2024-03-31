/*
 * Day: 60 | Date: 2024-03-31
 * Q060: Multiply Strings
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
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        int n = num1.size(), m = num2.size();
        vector<int> prod(n + m, 0);
        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 0; --j) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int sum = mul + prod[i + j + 1];
                prod[i + j + 1] = sum % 10;
                prod[i + j] += sum / 10;
            }
        }
        string res;
        int i = 0;
        while (i < (int)prod.size() - 1 && prod[i] == 0) ++i;
        for (; i < (int)prod.size(); ++i) res += char('0' + prod[i]);
        return res;
    }
};
