/*
 * Day: 117 | Date: 2024-05-27
 * Q117: Remove Duplicates from Sorted List II
 * Difficulty: Medium
 * Pattern: Linked List Manipulation
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(0, head);
        ListNode *prev = &dummy;
        while (head) {
            if (head->next && head->val == head->next->val) {
                int val = head->val;
                while (head && head->val == val) head = head->next;
                prev->next = head;
            } else {
                prev = prev->next;
                head = head->next;
            }
        }
        return dummy.next;
    }
};
