/*
 * Day: 58 | Date: 2024-03-29
 * Q058: Count and Say
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
    string countAndSay(int n) {
        string res = "1";
        for (int k = 2; k <= n; ++k) {
            string nxt;
            for (int i = 0; i < (int)res.size(); ) {
                int j = i;
                while (j < (int)res.size() && res[j] == res[i]) ++j;
                nxt += to_string(j - i);
                nxt += res[i];
                i = j;
            }
            res = move(nxt);
        }
        return res;
    }
};
