#ifndef QWEN_MAX_H
#define QWEN_MAX_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {
        vector<int> lis;
        for (int i = n - 1; i >= 0; --i) {
            auto it = lower_bound(lis.begin(), lis.end(), a[i]);
            if (it == lis.end()) {
                lis.push_back(a[i]);
            } else {
                *it = a[i];
            }
        }
        return n - lis.size();
    }
};

#endif