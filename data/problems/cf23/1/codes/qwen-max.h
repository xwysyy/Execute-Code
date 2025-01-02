#ifndef QWEN_MAX_H
#define QWEN_MAX_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {
        int max_length = 0;
        int current_length = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == 0) {
                current_length++;
                max_length = max(max_length, current_length);
            } else {
                current_length = 0;
            }
        }
        return max_length;
    }
};

#endif