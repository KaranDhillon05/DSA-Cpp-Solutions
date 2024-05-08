/*
 * Day: 98 | Date: 2024-05-08
 * Q098: Reverse Linked List II
 * Difficulty: Medium
 * Pattern: Linked List Reversal
 * Section: 3.2
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode dummy(0, head);
        ListNode *prev = &dummy;
        for (int i = 1; i < left; ++i) prev = prev->next;
        ListNode *cur = prev->next;
        for (int i = 0; i < right - left; ++i) {
            ListNode *nxt = cur->next;
            cur->next = nxt->next;
            nxt->next = prev->next;
            prev->next = nxt;
        }
        return dummy.next;
    }
};
