/*
 * Day: 130 | Date: 2024-06-09
 * Q130: Asteroid Collision
 * Difficulty: Medium
 * Pattern: Monotonic Stack
 * Section: Stacks & Queues
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;
        for (int a : asteroids) {
            bool alive = true;
            while (alive && !st.empty() && st.back() > 0 && a < 0) {
                if (st.back() < -a) { st.pop_back(); continue; }
                if (st.back() == -a) st.pop_back();
                alive = false;
                break;
            }
            if (alive) st.push_back(a);
        }
        return st;
    }
};
