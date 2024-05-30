/*
 * Day: 120 | Date: 2024-05-30
 * Q120: Convert Binary Number in a Linked List to Integer
 * Difficulty: Easy
 * Pattern: Linked List Math
 * Section: 3.3
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
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int res = 0;
        while (head) { res = (res << 1) | head->val; head = head->next; }
        return res;
    }
};
