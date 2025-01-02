#ifndef DEEPSEEK_CHAT_H
#define DEEPSEEK_CHAT_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(int &n, vector<int> &a) {
        long long maxBeauty = LLONG_MIN;
        for (int i = 0; i < n - 1; i++) {
            long long product = (long long)a[i] * a[i + 1];
            if (product > maxBeauty) {
                maxBeauty = product;
            }
        }
        return maxBeauty;
    }
};


#endif