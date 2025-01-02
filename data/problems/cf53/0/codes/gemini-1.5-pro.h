#ifndef GEMINI_1_5_PRO_H
#define GEMINI_1_5_PRO_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {
        vector<int> b = a;
        int min_disturbance = n;
        for (int i = 0; i < (1 << n); ++i) {
            vector<int> current_a = a;
            for (int j = 0; j < n; ++j) {
                if ((i >> j) & 1) {
                    swap(current_a[j], current_a[n - 1 - j]);
                }
            }

            int current_disturbance = 0;
            for (int j = 0; j < n - 1; ++j) {
                if (current_a[j] == current_a[j + 1]) {
                    current_disturbance++;
                }
            }
            min_disturbance = min(min_disturbance, current_disturbance);
        }
        return min_disturbance;
    }
};


#endif