#ifndef QWEN_MAX_H
#define QWEN_MAX_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(int &n, vector<int> &a) {   
        long long maxBeauty = LLONG_MIN;
        for (int i = 0; i < n - 1; ++i) {
            long long currentBeauty = (long long)a[i] * a[i + 1];
            maxBeauty = max(maxBeauty, currentBeauty);
        }
        return maxBeauty;
    }
};

#endif