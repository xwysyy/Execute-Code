#ifndef GEMINI_1_5_PRO_H
#define GEMINI_1_5_PRO_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {
        int max_len = 0;
        for (int i = 0; i < n; ++i) {
            int current_len = 0;
            int current_max = -1;
            for (int j = i; j < n; ++j) {
                if (a[j] >= current_max) {
                    current_len++;
                    current_max = a[j];
                }
            }
            max_len = max(max_len, current_len);
        }
        return n - max_len;
    }
};


#endif