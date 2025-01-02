#ifndef QWEN_MAX_H
#define QWEN_MAX_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {   
        int disturbance = 0;
        for (int i = 0; i < n / 2; ++i) {
            if (a[i] == a[n - i - 1]) {
                ++disturbance;
            }
        }
        return disturbance;
    }
};

#endif