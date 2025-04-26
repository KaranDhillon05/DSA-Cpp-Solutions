/*
 * Day: 451 | Date: 2025-04-26
 * Q451: Bulls and Cows
 * Difficulty: Medium
 * Pattern: Hashing
 * Section: 12 Hashing & Math
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0, cows = 0;
        int sCnt[10]{}, gCnt[10]{};
        for (int i = 0; i < (int)secret.size(); ++i) {
            if (secret[i] == guess[i]) ++bulls;
            else { ++sCnt[secret[i] - '0']; ++gCnt[guess[i] - '0']; }
        }
        for (int d = 0; d < 10; ++d) cows += min(sCnt[d], gCnt[d]);
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};
