/*
 * Day: 57 | Date: 2024-03-28
 * Q057: Integer to Roman
 * Difficulty: Medium
 * Pattern: String Basics
 * Section: 2.1
 *
 * Daily DSA practice — FAANG curated set (1 problem / day from 2024-02-01)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        vector<pair<int, string>> vals = {
            {1000,"M"},{900,"CM"},{500,"D"},{400,"CD"},{100,"C"},{90,"XC"},
            {50,"L"},{40,"XL"},{10,"X"},{9,"IX"},{5,"V"},{4,"IV"},{1,"I"}
        };
        string res;
        for (auto& [v, sym] : vals) {
            while (num >= v) { res += sym; num -= v; }
        }
        return res;
    }
};
