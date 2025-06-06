/*
 * Day: 492 | Date: 2025-06-06
 * Q492: Design an Ordered Stream
 * Difficulty: Easy
 * Pattern: Design
 * Section: 13 Design
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class OrderedStream {
    vector<string> buf;
    int ptr = 1;
public:
    OrderedStream(int n) : buf(n + 1) {}
    vector<string> insert(int id, string value) {
        buf[id] = value;
        vector<string> res;
        while (ptr < (int)buf.size() && !buf[ptr].empty()) res.push_back(buf[ptr++]);
        return res;
    }
};
