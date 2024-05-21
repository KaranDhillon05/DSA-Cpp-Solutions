/*
 * Day: 111 | Date: 2024-05-21
 * Q111: LRU Cache
 * Difficulty: Medium
 * Pattern: Linked List Design
 * Section: 3.2
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class LRUCache {
    int cap;
    list<pair<int,int>> order;
    unordered_map<int, list<pair<int,int>>::iterator> pos;
public:
    LRUCache(int capacity) : cap(capacity) {}
    int get(int key) {
        if (!pos.count(key)) return -1;
        order.splice(order.begin(), order, pos[key]);
        return pos[key]->second;
    }
    void put(int key, int value) {
        if (pos.count(key)) {
            order.splice(order.begin(), order, pos[key]);
            pos[key]->second = value;
            return;
        }
        if ((int)order.size() == cap) {
            pos.erase(order.back().first);
            order.pop_back();
        }
        order.emplace_front(key, value);
        pos[key] = order.begin();
    }
};
