#ifndef QWEN_MAX_H
#define QWEN_MAX_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> solve(int &n, int &m, vector<int> &a, vector<array<int, 3>> &ops) {
        vector<int> maxValues;
        for (auto &op : ops) {
            int type = op[0], l = op[1], r = op[2];
            for (int &x : a) {
                if (l <= x && x <= r) {
                    if (type == 1) x++;
                    else if (type == 2) x--;
                }
            }
            maxValues.push_back(*max_element(a.begin(), a.end()));
        }
        return maxValues;
    }
};


#endif