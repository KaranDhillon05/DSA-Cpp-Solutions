/*
 * Day: 427 | Date: 2025-04-02
 * Q427: Lemonade Change
 * Difficulty: Easy
 * Pattern: Greedy
 * Section: 11 Greedy
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;
        for (int b : bills) {
            if (b == 5) ++five;
            else if (b == 10) { if (!five) return false; --five; ++ten; }
            else {
                if (ten && five) { --ten; --five; }
                else if (five >= 3) five -= 3;
                else return false;
            }
        }
        return true;
    }
};
