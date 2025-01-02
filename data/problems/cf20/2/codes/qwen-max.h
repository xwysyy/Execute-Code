#ifndef QWEN_MAX_H
#define QWEN_MAX_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &t, vector<int> &a, vector<int> &b) {   
        int best_video = -1;
        int max_entertainment = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] <= t - i) {
                if (b[i] > max_entertainment) {
                    max_entertainment = b[i];
                    best_video = i + 1;
                }
            }
        }
        return best_video;
    }
};

#endif