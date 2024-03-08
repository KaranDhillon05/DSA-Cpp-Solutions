/*
 * Day: 37 | Date: 2024-03-08
 * Q037: Gas Station
 * Difficulty: Medium
 * Pattern: Kadane's / Greedy
 * Section: 1.4 Kadane's / Greedy
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalTank = 0, currTank = 0, start = 0;
        for (int i = 0; i < (int)gas.size(); ++i) {
            totalTank += gas[i] - cost[i];
            currTank += gas[i] - cost[i];
            if (currTank < 0) {
                start = i + 1;
                currTank = 0;
            }
        }
        return totalTank >= 0 ? start : -1;
    }
};
