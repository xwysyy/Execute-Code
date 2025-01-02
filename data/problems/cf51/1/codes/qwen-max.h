#ifndef QWEN_MAX_H
#define QWEN_MAX_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {   
        vector<int> lis;
        for (int x : a) {
            auto it = upper_bound(lis.begin(), lis.end(), x);
            if (it == lis.end()) {
                lis.push_back(x);
            } else {
                *it = x;
            }
        }
        return n - lis.size();
    }
};

#endif