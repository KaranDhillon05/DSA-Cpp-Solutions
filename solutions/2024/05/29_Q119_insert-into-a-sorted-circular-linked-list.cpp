/*
 * Day: 119 | Date: 2024-05-29
 * Q119: Insert into a Sorted Circular Linked List
 * Difficulty: Medium
 * Pattern: Linked List Manipulation
 * Section: 3.3
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node() {}
    Node(int _val) { val = _val; next = nullptr; }
    Node(int _val, Node* _next) { val = _val; next = _next; }
};

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        Node* node = new Node(insertVal);
        if (!head) { node->next = node; return node; }
        Node *prev = head, *cur = head->next;
        while (true) {
            if (prev->val <= insertVal && insertVal <= cur->val) break;
            if (prev->val > cur->val && (insertVal >= prev->val || insertVal <= cur->val)) break;
            prev = cur;
            cur = cur->next;
            if (prev == head) break;
        }
        prev->next = node;
        node->next = cur;
        return head;
    }
};
