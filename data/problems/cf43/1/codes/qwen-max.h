#ifndef QWEN_MAX_H
#define QWEN_MAX_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {   
        sort(a.begin(), a.end());
        int max_value = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] > max_value && (i + 1) * 2 >= n) {
                max_value = a[i];
            }
        }
        return max_value;
    }
};

#endif