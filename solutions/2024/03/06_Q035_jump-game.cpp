/*
 * Day: 35 | Date: 2024-03-06
 * Q035: Jump Game
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
    bool canJump(vector<int>& nums) {
        int reach = 0;
        for (int i = 0; i < (int)nums.size(); ++i) {
            if (i > reach) return false;
            reach = max(reach, i + nums[i]);
            if (reach >= (int)nums.size() - 1) return true;
        }
        return true;
    }
};
