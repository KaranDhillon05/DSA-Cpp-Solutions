/*
 * Day: 87 | Date: 2024-04-27
 * Q087: Remove Duplicate Letters
 * Difficulty: Medium
 * Pattern: Stack / Greedy
 * Section: 2.4
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> last(26, -1);
        for (int i = 0; i < (int)s.size(); ++i) last[s[i] - 'a'] = i;
        vector<bool> inStack(26, false);
        string st;
        for (int i = 0; i < (int)s.size(); ++i) {
            int c = s[i] - 'a';
            if (inStack[c]) continue;
            while (!st.empty() && st.back() > s[i] && last[st.back() - 'a'] > i) {
                inStack[st.back() - 'a'] = false;
                st.pop_back();
            }
            st.push_back(s[i]);
            inStack[c] = true;
        }
        return st;
    }
};
