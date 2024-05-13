/*
 * Day: 103 | Date: 2024-05-13
 * Q103: Sort List
 * Difficulty: Medium
 * Pattern: Linked List Merge
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
    ListNode* merge(ListNode* a, ListNode* b) {
        ListNode dummy(0);
        ListNode *tail = &dummy;
        while (a && b) {
            if (a->val <= b->val) { tail->next = a; a = a->next; }
            else { tail->next = b; b = b->next; }
            tail = tail->next;
        }
        tail->next = a ? a : b;
        return dummy.next;
    }
    pair<ListNode*, ListNode*> split(ListNode* head) {
        ListNode *slow = head, *fast = head, *prev = nullptr;
        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = nullptr;
        return {head, slow};
    }
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        auto [left, right] = split(head);
        return merge(sortList(left), sortList(right));
    }
};
