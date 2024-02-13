/*
 * Day: 13 | Date: 2024-02-13
 * Q013: Fruit Into Baskets
 * Difficulty: Medium
 * Pattern: Sliding Window
 * Section: 1.2 Sliding Window
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> freq;
        int l = 0, best = 0;
        for (int r = 0; r < (int)fruits.size(); ++r) {
            ++freq[fruits[r]];
            while ((int)freq.size() > 2) {
                --freq[fruits[l]];
                if (freq[fruits[l]] == 0) freq.erase(fruits[l]);
                ++l;
            }
            best = max(best, r - l + 1);
        }
        return best;
    }
};
