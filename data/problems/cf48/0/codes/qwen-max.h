#ifndef QWEN_MAX_H
#define QWEN_MAX_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> solve(int &n, int &m, vector<int> &a, vector<array<int, 3>> &ops) {
        vector<int> result;
        for (auto &op : ops) {
            int type = op[0], l = op[1], r = op[2];
            for (int &x : a) {
                if (l <= x && x <= r) {
                    if (type == 1) x++;
                    else if (type == 2) x--;
                }
            }
            int max_val = *max_element(a.begin(), a.end());
            result.push_back(max_val);
        }
        return result;
    }
};
// This solution directly applies the operations to the array and finds the maximum value after each operation. However, it may not be efficient enough for large inputs due to its time complexity. Consider using a more optimized approach, such as segment trees or difference arrays, for better performance.

#endif