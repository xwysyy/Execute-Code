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
        int max_count = 0;
        for (auto const& [key, val] : counts) {
            max_count = max(max_count, val);
        }
        return max_count;
    }
};


#endif