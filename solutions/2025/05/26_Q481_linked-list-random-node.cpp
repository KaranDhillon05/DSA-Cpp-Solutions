/*
 * Day: 481 | Date: 2025-05-26
 * Q481: Linked List Random Node
 * Difficulty: Medium
 * Pattern: Design
 * Section: 13 Design
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
    vector<int> vals;
    mt19937 rng{random_device{}()};
public:
    Solution(ListNode* head) {
        for (ListNode* cur = head; cur; cur = cur->next) vals.push_back(cur->val);
    }
    int getRandom() { return vals[rng() % vals.size()]; }
};
