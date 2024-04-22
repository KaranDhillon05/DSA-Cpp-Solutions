/*
 * Day: 82 | Date: 2024-04-22
 * Q082: Decode String
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
    string decodeString(string s) {
        stack<int> counts;
        stack<string> strings;
        strings.push("");
        int k = 0;
        for (char c : s) {
            if (isdigit(c)) k = k * 10 + (c - '0');
            else if (c == '[') { counts.push(k); strings.push(""); k = 0; }
            else if (c == ']') {
                string cur = strings.top(); strings.pop();
                int rep = counts.top(); counts.pop();
                while (rep--) strings.top() += cur;
            } else strings.top().push_back(c);
        }
        return strings.top();
    }
};
