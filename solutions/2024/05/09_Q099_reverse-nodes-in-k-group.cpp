/*
 * Day: 99 | Date: 2024-05-09
 * Q099: Reverse Nodes in k-Group
 * Difficulty: Hard
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
    pair<ListNode*, ListNode*> reverse(ListNode* head, int k) {
        ListNode *prev = nullptr, *cur = head;
        int cnt = 0;
        while (cur && cnt < k) { cur = cur->next; ++cnt; }
        if (cnt < k) return {head, nullptr};
        cur = head;
        cnt = 0;
        while (cnt < k) {
            ListNode *nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
            ++cnt;
        }
        head->next = cur;
        return {prev, head};
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0, head);
        ListNode *prevGroup = &dummy;
        while (head) {
            auto [newHead, tail] = reverse(head, k);
            if (!tail) break;
            prevGroup->next = newHead;
            prevGroup = tail;
            head = tail->next;
        }
        return dummy.next;
    }
};
