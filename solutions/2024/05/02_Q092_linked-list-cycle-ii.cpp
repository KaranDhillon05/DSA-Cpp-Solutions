/*
 * Day: 92 | Date: 2024-05-02
 * Q092: Linked List Cycle II
 * Difficulty: Medium
 * Pattern: Fast & Slow Pointers
 * Section: 3.1
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
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                ListNode *ptr = head;
                while (ptr != slow) { ptr = ptr->next; slow = slow->next; }
                return ptr;
            }
        }
        return nullptr;
    }
};
