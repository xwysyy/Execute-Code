#ifndef GEMINI_1_5_PRO_H
#define GEMINI_1_5_PRO_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {
        map<int, int> counts;
        for (int x : a) {
            counts[x]++;
        }
        for (auto const& [key, val] : counts) {
            if (val >= 3) {
                return key;
            }
        }
        return -1;
    }
};


#endif