#ifndef QWEN_MAX_H
#define QWEN_MAX_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &t, vector<int> &a, vector<int> &b) {   
        int best_index = -1;
        int max_entertainment = 0;
        for (int i = 0; i < n; ++i) {
            if (i + a[i] <= t) {
                if (b[i] > max_entertainment) {
                    max_entertainment = b[i];
                    best_index = i + 1; // +1 because the index is 1-based
                }
            }
        }
        return best_index;
    }
};

#endif