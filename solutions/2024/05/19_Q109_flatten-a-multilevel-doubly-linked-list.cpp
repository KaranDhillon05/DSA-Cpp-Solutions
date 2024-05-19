/*
 * Day: 109 | Date: 2024-05-19
 * Q109: Flatten a Multilevel Doubly Linked List
 * Difficulty: Medium
 * Pattern: Linked List DFS
 * Section: 3.2
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

class Solution {
    Node* dfs(Node* cur) {
        Node* tail = cur;
        while (cur) {
            Node* next = cur->next;
            if (cur->child) {
                Node* childHead = cur->child;
                Node* childTail = dfs(childHead);
                cur->next = childHead;
                childHead->prev = cur;
                childTail->next = next;
                if (next) next->prev = childTail;
                cur->child = nullptr;
                tail = next ? dfs(next) : childTail;
                break;
            }
            tail = cur;
            cur = next;
        }
        return tail;
    }
public:
    Node* flatten(Node* head) {
        if (head) dfs(head);
        return head;
    }
};
