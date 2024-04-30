/*
 * Day: 90 | Date: 2024-04-30
 * Q090: Valid Palindrome
 * Difficulty: Easy
 * Pattern: Two Pointers
 * Section: 2.4
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0, r = (int)s.size() - 1;
        while (l < r) {
            while (l < r && !isalnum(s[l])) ++l;
            while (l < r && !isalnum(s[r])) --r;
            if (tolower(s[l]) != tolower(s[r])) return false;
            ++l; --r;
        }
        return true;
    }
};
