#ifndef QWEN_MAX_H
#define QWEN_MAX_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> solve(int &n, vector<int> &a) {
        vector<int> result(n, 1);
        int max_cost = 1;
        for (int k = 1; k < n; ++k) {
            if (a[k] > a[k - 1]) {
                max_cost = 1;
            } else {
                max_cost++;
            }
            result[k] = max_cost;
        }
        return result;
    }
};

#endif