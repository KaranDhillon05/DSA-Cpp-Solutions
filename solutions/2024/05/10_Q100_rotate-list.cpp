/*
 * Day: 100 | Date: 2024-05-10
 * Q100: Rotate List
 * Difficulty: Medium
 * Pattern: Linked List Manipulation
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;
        int len = 1;
        ListNode *tail = head;
        while (tail->next) { ++len; tail = tail->next; }
        k %= len;
        if (k == 0) return head;
        tail->next = head;
        for (int i = 0; i < len - k; ++i) tail = tail->next;
        ListNode *newHead = tail->next;
        tail->next = nullptr;
        return newHead;
    }
};
