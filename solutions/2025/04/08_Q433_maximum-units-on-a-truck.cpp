/*
 * Day: 433 | Date: 2025-04-08
 * Q433: Maximum Units on a Truck
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
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](auto& a, auto& b) {
            return a[1] > b[1];
        });
        int res = 0;
        for (auto& b : boxTypes) {
            int take = min(truckSize, b[0]);
            res += take * b[1];
            truckSize -= take;
            if (!truckSize) break;
        }
        return res;
    }
};
