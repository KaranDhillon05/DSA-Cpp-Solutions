/*
 * Day: 113 | Date: 2024-05-23
 * Q113: Design Skiplist
 * Difficulty: Hard
 * Pattern: Linked List Design
 * Section: 3.3
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Skiplist {
    static const int MAX_LEVEL = 16;
    struct Node {
        int val;
        vector<Node*> next;
        Node(int v, int lvl) : val(v), next(lvl + 1, nullptr) {}
    };
    Node* head;
    int level;
    mt19937 rng{random_device{}()};
public:
    Skiplist() : head(new Node(-1, MAX_LEVEL)), level(0) {}
    bool search(int target) {
        Node* cur = head;
        for (int i = level; i >= 0; --i) {
            while (cur->next[i] && cur->next[i]->val < target) cur = cur->next[i];
        }
        cur = cur->next[0];
        return cur && cur->val == target;
    }
    void add(int num) {
        vector<Node*> update(MAX_LEVEL + 1, head);
        Node* cur = head;
        for (int i = level; i >= 0; --i) {
            while (cur->next[i] && cur->next[i]->val < num) cur = cur->next[i];
            update[i] = cur;
        }
        int lvl = 0;
        while (lvl < MAX_LEVEL && (rng() & 1)) ++lvl;
        if (lvl > level) {
            for (int i = level + 1; i <= lvl; ++i) update[i] = head;
            level = lvl;
        }
        Node* node = new Node(num, lvl);
        for (int i = 0; i <= lvl; ++i) {
            node->next[i] = update[i]->next[i];
            update[i]->next[i] = node;
        }
    }
    bool erase(int num) {
        vector<Node*> update(MAX_LEVEL + 1, head);
        Node* cur = head;
        for (int i = level; i >= 0; --i) {
            while (cur->next[i] && cur->next[i]->val < num) cur = cur->next[i];
            update[i] = cur;
        }
        cur = cur->next[0];
        if (!cur || cur->val != num) return false;
        for (int i = 0; i <= level; ++i) {
            if (update[i]->next[i] != cur) break;
            update[i]->next[i] = cur->next[i];
        }
        while (level > 0 && !head->next[level]) --level;
        delete cur;
        return true;
    }
};
