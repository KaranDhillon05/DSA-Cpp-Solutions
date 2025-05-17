/*
 * Day: 472 | Date: 2025-05-17
 * Q472: LFU Cache
 * Difficulty: Hard
 * Pattern: Design
 * Section: 13 Design
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class LFUCache {
    int cap, minFreq;
    unordered_map<int, pair<int,int>> keyValFreq;
    unordered_map<int, list<int>> freqList;
    unordered_map<int, unordered_map<int, list<int>::iterator>> keyIter;
public:
    LFUCache(int capacity) : cap(capacity), minFreq(0) {}
    int get(int key) {
        if (!keyValFreq.count(key)) return -1;
        touch(key);
        return keyValFreq[key].first;
    }
    void put(int key, int value) {
        if (cap == 0) return;
        if (keyValFreq.count(key)) {
            keyValFreq[key].first = value;
            touch(key);
            return;
        }
        if ((int)keyValFreq.size() == cap) {
            int evict = freqList[minFreq].back();
            freqList[minFreq].pop_back();
            keyValFreq.erase(evict);
            keyIter[minFreq].erase(evict);
        }
        minFreq = 1;
        freqList[1].push_front(key);
        keyIter[1][key] = freqList[1].begin();
        keyValFreq[key] = {value, 1};
    }
private:
    void touch(int key) {
        int val = keyValFreq[key].first;
        int f = keyValFreq[key].second;
        freqList[f].erase(keyIter[f][key]);
        if (freqList[f].empty() && f == minFreq) ++minFreq;
        ++f;
        freqList[f].push_front(key);
        keyIter[f][key] = freqList[f].begin();
        keyValFreq[key] = {val, f};
    }
};
