/*
 * Day: 441 | Date: 2025-04-16
 * Q441: Boats to Save People
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
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int boats = 0, l = 0, r = people.size() - 1;
        while (l <= r) {
            if (people[l] + people[r] <= limit) ++l;
            --r;
            ++boats;
        }
        return boats;
    }
};
