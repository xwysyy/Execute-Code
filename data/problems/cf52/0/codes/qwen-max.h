#ifndef QWEN_MAX_H
#define QWEN_MAX_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(int &n, vector<vector<int>> &a) {   
        long long operations = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (a[i][j] < 0) {
                    int required_increase = abs(a[i][j]) + 1;
                    a[i][j] += required_increase;
                    operations += required_increase;
                    for (int k = 1; i + k < n && j + k < n; ++k) {
                        a[i + k][j + k] += required_increase;
                    }
                }
            }
        }
        return operations;
    }
};

#endif