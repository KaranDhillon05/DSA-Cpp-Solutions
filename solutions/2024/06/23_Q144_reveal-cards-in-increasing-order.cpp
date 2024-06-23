/*
 * Day: 144 | Date: 2024-06-23
 * Q144: Reveal Cards In Increasing Order
 * Difficulty: Medium
 * Pattern: Queue/Deque
 * Section: Stacks & Queues
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());
        int n = deck.size();
        deque<int> dq;
        for (int i = n - 1; i >= 0; --i) {
            if (!dq.empty()) { dq.push_front(dq.back()); dq.pop_back(); }
            dq.push_front(deck[i]);
        }
        return vector<int>(dq.begin(), dq.end());
    }
};
