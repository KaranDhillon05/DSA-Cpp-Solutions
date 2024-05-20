/*
 * Day: 110 | Date: 2024-05-20
 * Q110: Copy List with Random Pointer
 * Difficulty: Medium
 * Pattern: Linked List Clone
 * Section: 3.2
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        unordered_map<Node*, Node*> clone;
        for (Node* cur = head; cur; cur = cur->next)
            clone[cur] = new Node(cur->val);
        for (Node* cur = head; cur; cur = cur->next) {
            clone[cur]->next = clone.count(cur->next) ? clone[cur->next] : nullptr;
            clone[cur]->random = clone.count(cur->random) ? clone[cur->random] : nullptr;
        }
        return clone[head];
    }
};
